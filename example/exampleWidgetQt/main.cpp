#include "MainWindow.h"
#include "TicTacToeGame.h"
#include "HumanPlayer.h"
#include <QApplication>
#include <QMessageBox>


int main(int argc, char* argv[])
{
    TicTacToeGame* game = new TicTacToeGame();
    QApplication a(argc, argv);
    MainWindow w(game);
    w.show();
    return a.exec();
}
