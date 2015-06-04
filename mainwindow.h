#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "board.h"
#include <QObject>

/** @class MainWindow
 * @brief The MainWindow class controls the menu systems of the game. It enables the game to entirely run in a single window.
 *
 * MainWindow publicly derives from the QMainWindow class.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    /**
     * @brief play is a custom slot that sets up the game being played for the first time
     */
    void play();
    /**
     * @brief play2 is a custom slot that resets the game after the player has been defeated or wins the game
     */
    void play2();
    /**
     * @brief instructions_page is a custom slot that opens up the instructions page of the menu interface
     */
    void instructions_page();
    /**
     * @brief credits_page is a custom slot that opens up the credits page of the menu interface
     */
    void credits_page();
    /**
     * @brief back is a custom slot that brings the player back to the main menu from the instructions or credits pages
     */
    void back();
    /**
     * @brief quit is a custom slot that terminates the program
     */
    void quit();
    /**
     * @brief game_over is a custom slot that sets up the game over page of the menu system
     */
    void game_over();
    /**
     * @brief victory is a custom slot that sets up the victory screen of the game
     */
    void victory();
public:
    /**
     * @brief MainWindow
     * @param parent is the parent QWidget of the MainWindow object
     */
    MainWindow(QWidget *parent = 0);
    /**
      * @brief MainWindow destructor
      */
    ~MainWindow();
private:
    QStackedWidget* pages;
    QWidget* main;
    QWidget* instructions_widget;
    QWidget* credits_widget;
    Board* game_board;
};

#endif // MAINWINDOW_H
