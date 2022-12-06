/**
 * @file 
 * @author 
 * @brief 
 * @version 
 * @date 
 * 
 * @copyright Copyright (c) 2022
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TicTacToeGame.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @details Class for MainWindow objects
*/
class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
   /**
    * @brief Constructor for MainWindow
    * 
    * @param parent Widget for the main window
   */
    explicit MainWindow(QWidget* parent = nullptr);

    /**
     * @brief Destructor for MainWindow
    */
    ~MainWindow();

    /**
     * @brief Check if the game is over
     * 
     * @return Return a ture or false value
    */
    bool gameOver();

   /**
    * @brief End the game
   */
    void endGame();

    /**
     * @brief Start a new game
    */
    void newGame();

    /**
     * @brief Pop-up window for new game
    */
    void newGamePopUp();

    /*
    * @brief Executes the computer player's turn
    */
    void computerMove();

 private slots:
   /**
    * @brief Action when button 1 is clicked
   */
   void on_button1_clicked();

   /**
    * @brief Action when button 2 is clicked
   */
   void on_button2_clicked();

   /**
    * @brief Action when button 3 is clicked
   */
   void on_button3_clicked();
    
   /**
    * @brief Action when button 4 is clicked
   */
   void on_button4_clicked();
    
   /**
    * @brief Action when button 5 is clicked
   */
   void on_button5_clicked();
    
   /**
    * @brief Action when button 6 is clicked
   */
   void on_button6_clicked();
   
   /**
    * @brief Action when button 7 is clicked
   */
   void on_button7_clicked();
   
   /**
    * @brief Action when button 8 is clicked
   */
   void on_button8_clicked();
   
   /**
    * @brief Action when button 9 is clicked
   */
   void on_button9_clicked();

   void gameTypePopUp();

 private:
    Ui::MainWindow *ui;
    std::shared_ptr<IBoardGame> game;
    std::unique_ptr<IPlayer> player1;
    std::unique_ptr<IPlayer> player2;
    bool singleplayer = false;
};
#endif  // MAINWINDOW_H
