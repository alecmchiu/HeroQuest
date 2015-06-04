#include "board.h"
#include "portal.h"
#include "player.h"
#include "boss.h"
#include "switch.h"
#include "wall.h"
#include <cstdlib>
#include <ctime>
#include "no_arrow_boss.h"
#include "fire_wall.h"
#include "minion_boss.h"

Board::Board(QWidget *parent) : QGraphicsView(parent),bosses(3)
{
    srand(int(time(0)));

    main_room = new Room(QPixmap(":/images/dirt.png"));
    Room1 = new Room(QPixmap(":/images/metal.png"));
    Room2 = new Room(QPixmap(":/images/floor.jpg"));
    Room3 = new Room(QPixmap(":/images/stone.png"));

    //main_room construction

    Portal* first = new Portal(Room1, this);
    main_room->addItem(first);
    first->setPos(0,300);

    Portal* second = new Portal(Room2, this);
    main_room->addItem(second);
    second->setPos(530,300);

    Portal* third = new Portal(Room3, this);
    main_room->addItem(third);
    third->setPos(300,0);

    //Room1 Construction

    Portal* OneToMain = new Portal(main_room, this);
    Room1->addItem(OneToMain);
    OneToMain->setPos(530,300);
    boss* one = new boss(QPixmap(":/images/boss1.png"),0,'r');
    one->setScale(0.75);
    Room1->addItem(one);
    wall* boss_wall = new wall(QPixmap(":/images/vert_thunder.png"));
    Room1->addItem(boss_wall);
    boss_wall->setPos(150,0);

    Switch* switch1 = new Switch();
    switch1->setScale(0.5);
    switch1->setPos(450,0);
    Switch* switch2 = new Switch();
    switch2->setScale(0.5);
    switch2->setPos(300, 0);
    Switch* switch3 = new Switch();
    switch3->setScale(0.5);
    switch3->setPos(450, 550);
    Switch* switch4 = new Switch();
    switch4->setScale(0.5);
    switch4->setPos(300,550);
    int switch_number = rand()%4 + 1;

    Room1->addItem(switch1);
    Room1->addItem(switch2);
    Room1->addItem(switch3);
    Room1->addItem(switch4);

    //Room2 Construction

    Portal* TwoToMain = new Portal(main_room, this);
    Room2->addItem(TwoToMain);
    TwoToMain->setPos(0,300);
    no_arrow_boss* two = new no_arrow_boss(QPixmap(":/images/Boss2.png"),0,'l');
    two->setPos(400,0);
    two->setScale(0.75);
    fire_wall* wall1 = new fire_wall();
    wall1->setPos(300,300);
    wall1->setScale(0.5);
    Room2->addItem(two);
    Room2->addItem(wall1);

    //Room3 Construction

    Portal* ThreeToMain = new Portal(main_room, this);
    Room3->addItem(ThreeToMain);
    ThreeToMain->setPos(300,520);
    minion_boss* three = new minion_boss(QPixmap(":/images/Boss3.png"),2,'d');
    three->setScale(0.3);
    Room3->addItem(three);

    //Begin

    setFixedSize(600,600);
    setScene(main_room);

    user = new Player(QPixmap(":/images/link.png"));
    user->setPos(300,300);
    main_room->addItem(user);
    user->setFocus();

    connect(user,SIGNAL(PortalCollision(QGraphicsItem*)),first,SLOT(Collided(QGraphicsItem*)));
    connect(user,SIGNAL(PortalCollision(QGraphicsItem*)),second,SLOT(Collided(QGraphicsItem*)));
    connect(user,SIGNAL(PortalCollision(QGraphicsItem*)),third,SLOT(Collided(QGraphicsItem*)));
    connect(user,SIGNAL(PortalCollision(QGraphicsItem*)),OneToMain,SLOT(Collided(QGraphicsItem*)));
    connect(user,SIGNAL(PortalCollision(QGraphicsItem*)),TwoToMain,SLOT(Collided(QGraphicsItem*)));
    connect(user,SIGNAL(PortalCollision(QGraphicsItem*)),ThreeToMain,SLOT(Collided(QGraphicsItem*)));

    connect(user,SIGNAL(GameOver()),this,SLOT(game_over()));

    if (switch_number == 1){
        connect(user,SIGNAL(SwitchCollision(QGraphicsItem*)),switch1,SLOT(activate(QGraphicsItem*)));
        connect(switch1,SIGNAL(green()),boss_wall,SLOT(deactivate()));
    }

    if (switch_number == 2){
        connect(user,SIGNAL(SwitchCollision(QGraphicsItem*)),switch2,SLOT(activate(QGraphicsItem*)));
        connect(switch2,SIGNAL(green()),boss_wall,SLOT(deactivate()));
    }

    if (switch_number == 3){
        connect(user,SIGNAL(SwitchCollision(QGraphicsItem*)),switch3,SLOT(activate(QGraphicsItem*)));
        connect(switch3,SIGNAL(green()),boss_wall,SLOT(deactivate()));
    }

    if (switch_number == 4){
        connect(user,SIGNAL(SwitchCollision(QGraphicsItem*)),switch4,SLOT(activate(QGraphicsItem*)));
        connect(switch4,SIGNAL(green()),boss_wall,SLOT(deactivate()));
    }

    connect(one,SIGNAL(destroyed()),boss_wall,SLOT(nullify()));

    connect(one,SIGNAL(destroyed()),this,SLOT(boss_kill()));
    connect(two,SIGNAL(destroyed()),this,SLOT(boss_kill()));
    connect(three,SIGNAL(destroyed()),this,SLOT(boss_kill()));
}

void Board::PortalWarp(Room *a){
    setScene(a);
    if (user->pos().x() < 300 && 200 < user->pos().y() && user->pos().y() < 400){
        user->x = 450;
        user->y = 300;
        user->setPos(user->x,user->y);
    }
    else if (user->pos().x() > 300 && 200 < user->pos().y() && user->pos().y() < 400){
        user->x = 80;
        user->y = 300;
        user->setPos(user->x,user->y);
    }
    else if (user->pos().y() < 300){
        user->x = 300;
        user->y = 450;
        user->setPos(user->x,user->y);
    }
    else if (user->pos().y() > 300){
        user->x = 300;
        user->y = 80;
        user->setPos(user->x, user->y);
    }
    a->addItem(user);
    user->setFocus();
}

void Board::game_over()
{
    emit defeat();
    delete this;
}

void Board::boss_kill()
{
    bosses--;
    if(bosses == 0){
        emit win();
    }
}


Board::~Board()
{

}

