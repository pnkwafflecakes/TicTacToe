#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "./include/TicTacToeGame.h"
#include "./include/HumanPlayer.h"
#include "./include/ComputerPlayer.h"
#include <QMessageBox>
#include <QTimer>
#include <iostream>

MainWindow::MainWindow(TicTacToeGame * i_game, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = i_game;
    QTimer::singleShot(0, this, SLOT(gameTypePopUp()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}


void MainWindow::on_button1_clicked()
{
    int num = game->getBoardSize();
    char letter = game->getCurrentPlayer()->getLetter();
    
    if (game->modifyTile(0, 0, letter) == true) {
        const QString stringL(letter);
        ui->button1->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

void MainWindow::on_button2_clicked()
{
    char letter = game->getCurrentPlayer()->getLetter();
    if (game->modifyTile(0, 1, letter) == true) {
        const QString stringL(letter);
        ui->button2->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

void MainWindow::on_button3_clicked()
{
    char letter = game->getCurrentPlayer()->getLetter();
    if (game->modifyTile(0, 2, letter) == true) {
        const QString stringL(letter);
        ui->button3->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}
void MainWindow::on_button4_clicked()
{
    char letter = game->getCurrentPlayer()->getLetter();
    if (game->modifyTile(1, 0, letter) == true) {
        const QString stringL(letter);
        ui->button4->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

void MainWindow::on_button5_clicked()
{
    char letter = game->getCurrentPlayer()->getLetter();
    if (game->modifyTile(1, 1, letter) == true) {
        const QString stringL(letter);
        ui->button5->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

void MainWindow::on_button6_clicked()
{
    char letter = game->getCurrentPlayer()->getLetter();
    if (game->modifyTile(1, 2, letter) == true) {
        const QString stringL(letter);
        ui->button6->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

void MainWindow::on_button7_clicked()
{
    char letter = game->getCurrentPlayer()->getLetter();
    if (game->modifyTile(2, 0, letter) == true) {
        const QString stringL(letter);
        ui->button7->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

void MainWindow::on_button8_clicked()
{
    char letter = game->getCurrentPlayer()->getLetter();
    if (game->modifyTile(2, 1, letter) == true) {
        const QString stringL(letter);
        ui->button8->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

void MainWindow::on_button9_clicked()
{
    char letter = game->getCurrentPlayer()->getLetter();
    if (game->modifyTile(2, 2, letter) == true) {
        const QString stringL(letter);
        ui->button9->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

bool MainWindow::gameOver() {
    if (game->checkEnd() == -1) {
        return false;
    }
    else {
        return true;
    }
}

void MainWindow::endGame() {
    if (gameOver()) {
        if (game->checkEnd() == 2) {
            QMessageBox::information(
                this,
                tr("TicTacToe"),
                tr("Player-X Wins!"));
            newGamePopUp();
            //add delete game callmethod
        }
        else if (game->checkEnd() == 1) {
            QMessageBox::information(
                this,
                tr("TicTacToe"),
                tr("Player-O Wins!"));
            newGamePopUp();
            //add delete game callmethod
        }
        else if (game->checkEnd() == 0) {
            QMessageBox::information(
                this,
                tr("TicTacToe"),
                tr("Draw!"));
            //add delete game callmethod
            newGamePopUp();
        }
    }
}

void MainWindow::gameTypePopUp() {
    switch (QMessageBox::question(
        this,
        tr("TicTacToe"),
        tr("Singleplayer?"),

        QMessageBox::Yes |
        QMessageBox::No))
    {
    case QMessageBox::Yes:
        singleplayer = true;
        newGame();
        qDebug("yes");
        break;
    case QMessageBox::No:
        singleplayer = false;
        newGame();
        qDebug("no");
        break;
    default:
        qDebug("default");
        break;
    }
}

void MainWindow::newGame() {
    if (singleplayer == true) {
        std::pair<IPlayer*, IPlayer*> players = game->getPlayers();
        HumanPlayer* player1 = new HumanPlayer(players.first->getLetter(), players.first->getPlayerNum());
        HumanPlayer* player2 = new HumanPlayer(players.second->getLetter(), players.second->getPlayerNum());
        game = new TicTacToeGame();
        game->assignPlayer(player1);
        game->assignPlayer(player2);
    }

    else if (singleplayer = false) {
        std::pair<IPlayer*, IPlayer*> players =
        std::pair(new HumanPlayer('X', 1), new HumanPlayer('O', 2));
        game->createBoard(3);
        game->setPlayers(players);
        char let = game->getCurrentPlayer()->getLetter();
    }
    
    
    ui->button1->setText("");
    ui->button2->setText("");
    ui->button3->setText("");
    ui->button4->setText("");
    ui->button5->setText("");
    ui->button6->setText("");
    ui->button7->setText("");
    ui->button8->setText("");
    ui->button9->setText("");
}

void MainWindow::newGamePopUp() {
    switch (QMessageBox::question(
        this,
        tr("TicTacToe"),
        tr("New Game?"),

        QMessageBox::Yes |
        QMessageBox::No))
    {
    case QMessageBox::Yes:
        newGame();
        qDebug("yes");
        break;
    case QMessageBox::No:
        newGame();
        qDebug("no");
        break;
    default:
        qDebug("default");
        break;
    }
}
