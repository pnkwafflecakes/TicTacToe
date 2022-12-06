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
#include <QMessageBox>
#include <iostream>
#include <utility>
#include "./ui_MainWindow.h"
#include "TicTacToeGame.h"
#include "HumanPlayer.h"

/**
 * @brief Implemented constructor for MainWindow
 * 
 * @param parent Widget for the main window
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    game.reset(new TicTacToeGame());
    player1.reset(new HumanPlayer('X', 1));
    player2.reset(new HumanPlayer('O', 2));
    game.get()->assignPlayer(std::move(player1));
    game.get()->assignPlayer(std::move(player2));
}

/**
 * @brief Implemented destructor for MainWindow
*/
MainWindow::~MainWindow() {
    delete ui;
}

/**
 * @brief On button 1 click attempt to modify tile and check if game is over
*/
void MainWindow::on_button1_clicked() {
    char letter = game->getCurrentLetter();

    if (game->modifyTile(0, 0, letter) == true) {
        const QString stringL(letter);
        ui->button1->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

/**
 * @brief On button 2 click attempt to modify tile and check if game is over
*/
void MainWindow::on_button2_clicked() {
    char letter = game->getCurrentLetter();
    if (game->modifyTile(0, 1, letter) == true) {
        const QString stringL(letter);
        ui->button2->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

/**
 * @brief On button 3 click attempt to modify tile and check if game is over
*/
void MainWindow::on_button3_clicked() {
    char letter = game->getCurrentLetter();
    if (game->modifyTile(0, 2, letter) == true) {
        const QString stringL(letter);
        ui->button3->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

/**
 * @brief On button 4 click attempt to modify tile and check if game is over
*/
void MainWindow::on_button4_clicked() {
    char letter = game->getCurrentLetter();
    if (game->modifyTile(1, 0, letter) == true) {
        const QString stringL(letter);
        ui->button4->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

/**
 * @brief On button 5 click attempt to modify tile and check if game is over
*/
void MainWindow::on_button5_clicked() {
    char letter = game->getCurrentLetter();
    if (game->modifyTile(1, 1, letter) == true) {
        const QString stringL(letter);
        ui->button5->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

/**
 * @brief On button 6 click attempt to modify tile and check if game is over
*/
void MainWindow::on_button6_clicked() {
    char letter = game->getCurrentLetter();
    if (game->modifyTile(1, 2, letter) == true) {
        const QString stringL(letter);
        ui->button6->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

/**
 * @brief On button 7 click attempt to modify tile and check if game is over
*/
void MainWindow::on_button7_clicked() {
    char letter = game->getCurrentLetter();
    if (game->modifyTile(2, 0, letter) == true) {
        const QString stringL(letter);
        ui->button7->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

/**
 * @brief On button 8 click attempt to modify tile and check if game is over
*/
void MainWindow::on_button8_clicked() {
    char letter = game->getCurrentLetter();
    if (game->modifyTile(2, 1, letter) == true) {
        const QString stringL(letter);
        ui->button8->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

/**
 * @brief On button 9 click attempt to modify tile and check if game is over
*/
void MainWindow::on_button9_clicked() {
    char letter = game->getCurrentLetter();
    if (game->modifyTile(2, 2, letter) == true) {
        const QString stringL(letter);
        ui->button9->setText(stringL);
        game->endTurn();
        if (gameOver()) {
            endGame();
        }
    }
}

/**
 * @brief Check if the game is over
 * 
 * @return Return a ture or false value
*/
bool MainWindow::gameOver() {
    if (game->checkEnd() == -1) {
        return false;
    } else {
        return true;
    }
}

/**
 * @brief End the game
*/
void MainWindow::endGame() {
    if (gameOver()) {
        if (game->checkEnd() == 2) {
            QMessageBox::information(
                this,
                tr("TicTacToe"),
                tr("Player-X Wins!"));
            newGamePopUp();
        } else if (game->checkEnd() == 1) {
            QMessageBox::information(
                this,
                tr("TicTacToe"),
                tr("Player-O Wins!"));
            newGamePopUp();
        } else if (game->checkEnd() == 0) {
            QMessageBox::information(
                this,
                tr("TicTacToe"),
                tr("Draw!"));
            newGamePopUp();
        }
    }
}

/**
 * @brief Create a new game
*/
void MainWindow::newGame() {
    game.reset(new TicTacToeGame());
    player1.reset(new HumanPlayer('X', 1));
    player2.reset(new HumanPlayer('O', 2));
    game->assignPlayer(std::move(player1));
    game->assignPlayer(std::move(player2));

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

/**
 * @brief Ask the players if they would like to play another game
*/
void MainWindow::newGamePopUp() {
    switch (QMessageBox::question(
        this,
        tr("TicTacToe"),
        tr("New Game?"),

        QMessageBox::Yes |
        QMessageBox::No)) {
    case QMessageBox::Yes:
        newGame();
        qDebug("yes");
        break;
    case QMessageBox::No:
        this->close();
        qDebug("no");
        break;
    default:
        this->close();
        break;
    }
}
