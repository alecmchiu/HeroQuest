#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include "board.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    game_board = new Board();
    setWindowTitle("Hero Quest");
    setFixedSize(600,600);

    main = new QWidget();
    QVBoxLayout* main_layout = new QVBoxLayout();
    main->setLayout(main_layout);

    QLabel* title = new QLabel("<b>Hero Quest</b>");
    title->setAlignment(Qt::AlignHCenter);

    QPixmap* logo = new QPixmap(":/images/HeroQuestLogoPixels5.png");
    QLabel* logo_label = new QLabel();
    logo_label->setPixmap(*logo);
    logo_label->setAlignment(Qt::AlignHCenter);

    QVBoxLayout* buttons = new QVBoxLayout();
    QPushButton* start = new QPushButton("Start");

    QPushButton* instructions = new QPushButton("Instructions");
    QPushButton* credits = new QPushButton("Credits");

    buttons->addWidget(start);
    buttons->addWidget(instructions);
    buttons->addWidget(credits);

    main_layout->addWidget(title);
    main_layout->addWidget(logo_label);
    main_layout->addLayout(buttons);

    //

    instructions_widget = new QWidget();
    QVBoxLayout* instructions_layout = new QVBoxLayout();
    instructions_widget->setLayout(instructions_layout);
    QLabel* title_2 = new QLabel("<b>Instructions</b>");
    title_2->setAlignment(Qt::AlignHCenter);
    QLabel* text = new QLabel("Use <b>WASD</b> keys to move.<br>Use <b>spacebar</b> to shoot arrows (1 second cooldown).<br>Use the <b>blue portals</b> to travel between rooms.<br>You will encounter <b>different obstacles</b> that you must <b>discover</b> and <b>overcome</b>!<br>Each boss will have a <b>unique mechanic</b> to defeat it.<br><b>Defeat</b> the three bosses to win!");
    text->setAlignment(Qt::AlignTop);
    QPushButton* back = new QPushButton("Back");
    instructions_layout->addWidget(title_2);
    instructions_layout->addWidget(text);
    instructions_layout->addWidget(back);
    connect(back,SIGNAL(clicked()),this,SLOT(back()));

    //

    credits_widget = new QWidget();
    QVBoxLayout* credits_layout = new QVBoxLayout();
    credits_widget ->setLayout(credits_layout);
    QLabel* credits_title = new QLabel("<b>Credits</b>");
    credits_title->setAlignment(Qt::AlignHCenter);
    QLabel* credits_list = new QLabel("Programmed and Created by <b>Alec Chiu</b>.<br>Special Thanks to <b>Dr. Stephen DeSalvo</b> for instruction in his PIC 10C class.</b><br>Special Thanks to <b>Abdullah Aghazadah</b> for his YouTube Qt tutorials.<br>Special Thanks for <b>Arman Farhangi</b> for support and example code from his project.<br>*** <b>Extra Special Thanks</b> to creators of the resources that I have used in this project. ***");
    credits_list->setAlignment(Qt::AlignTop);
    QPushButton* back2 = new QPushButton("Back");
    credits_layout->addWidget(credits_title);
    credits_layout->addWidget(credits_list);
    credits_layout->addWidget(back2);
    connect(back2,SIGNAL(clicked()),this,SLOT(back()));

    //

    pages = new QStackedWidget();
    pages->addWidget(main);
    pages->addWidget(instructions_widget);
    pages->addWidget(credits_widget);

    connect(instructions,SIGNAL(clicked()),this,SLOT(instructions_page()));
    connect(credits,SIGNAL(clicked()),this,SLOT(credits_page()));

    connect(start,SIGNAL(clicked()),this,SLOT(play()));

    connect(game_board,SIGNAL(defeat()),this,SLOT(game_over()));
    connect(game_board,SIGNAL(win()),this,SLOT(victory()));

    setCentralWidget(pages);

}

void MainWindow::instructions_page(){
    pages->setCurrentWidget(instructions_widget);
}

void MainWindow::credits_page(){
    pages->setCurrentWidget(credits_widget);
}

void MainWindow::back(){
    pages->setCurrentWidget(main);
}

void MainWindow::play(){
    setCentralWidget(game_board);
}

void MainWindow::play2(){
    game_board = new Board;
    connect(game_board,SIGNAL(defeat()),this,SLOT(game_over()));
    connect(game_board,SIGNAL(win()),this,SLOT(victory()));
    setCentralWidget(game_board);
}

void MainWindow::game_over(){

    QWidget* game_over_widget = new QWidget();
    QVBoxLayout* game_over_layout = new QVBoxLayout();
    game_over_widget->setLayout(game_over_layout);
    QLabel* game_over_title = new QLabel("<h1>Game Over!</h1>");
    game_over_title->setAlignment(Qt::AlignHCenter);
    QPushButton* play_again = new QPushButton("Play Again");
    QPushButton* quit_button = new QPushButton("Quit");
    QPixmap* pic = new QPixmap(":/images/defeat.png");
    QLabel* defeat_pic = new QLabel();
    defeat_pic->setPixmap(*pic);
    defeat_pic->setAlignment(Qt::AlignHCenter);
    game_over_layout->addWidget(game_over_title);
    game_over_layout->addWidget(defeat_pic);
    game_over_layout->addWidget(play_again);
    game_over_layout->addWidget(quit_button);

    connect(play_again,SIGNAL(clicked()),this,SLOT(play2()));
    connect(quit_button,SIGNAL(clicked()),this,SLOT(quit()));

    setCentralWidget(game_over_widget);
}

void MainWindow::victory()
{
    QWidget* victory_widget = new QWidget();
    QVBoxLayout* victory_layout = new QVBoxLayout();
    victory_widget->setLayout(victory_layout);
    QLabel* victory_title = new QLabel("<h1>Victory!</h1>");
    victory_title->setAlignment(Qt::AlignHCenter);
    QPushButton* play_again2 = new QPushButton("Play Again");
    QPushButton* quit_button2 = new QPushButton("Quit");
    QLabel* win_label = new QLabel();
    win_label->setPixmap(QPixmap(":/images/victory.png"));
    win_label->setAlignment(Qt::AlignHCenter);

    victory_layout->addWidget(victory_title);
    victory_layout->addWidget(win_label);
    victory_layout->addWidget(play_again2);
    victory_layout->addWidget(quit_button2);

    connect(play_again2,SIGNAL(clicked()),this,SLOT(play2()));
    connect(quit_button2,SIGNAL(clicked()),this,SLOT(quit()));

    setCentralWidget(victory_widget);
}

void MainWindow::quit(){
    this->close();
}

MainWindow::~MainWindow()
{

}
