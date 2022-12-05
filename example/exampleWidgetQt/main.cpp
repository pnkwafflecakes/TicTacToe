/**
 * @file 
 * @author 
 * @brief 
 * @version 
 * @date 
 * 
 * @copyright Copyright (c) 2022
 */

#include "MainWindow.h"
#include "TicTacToeGame.h"
#include "HumanPlayer.h"
#include <QApplication>


int main(int argc, char *argv[]) {
    /*TicTacToeGame* game = new TicTacToeGame();
    HumanPlayer* player1 = new HumanPlayer('X', 1);
    HumanPlayer* player2 = new HumanPlayer('O', 2);
    game->assignPlayer(player1);
    game->assignPlayer(player2);*/
    QApplication a(argc, argv);
    MainWindow w();
    w.show();
    return a.exec();
}
