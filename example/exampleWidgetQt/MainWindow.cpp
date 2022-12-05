#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "TicTacToeGame.h"
#include <iostream>

MainWindow::MainWindow(TicTacToeGame* i_game, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = i_game;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}


void MainWindow::on_button1_clicked()
{
    if (game->modifyTile(0, 0, game->getCurrentPlayer()->getLetter()) == true) {
        const QString letter(game->getCurrentPlayer()->getLetter());
        ui->button1->setText(letter);
    }
}

void MainWindow::on_button2_clicked()
{
    if (game->modifyTile(0, 1, game->getCurrentPlayer()->getLetter()) == true) {
        const QString letter(game->getCurrentPlayer()->getLetter());
        ui->button1->setText(letter);
    }
}

void MainWindow::on_button3_clicked()
{
    ui->button3->setText("X");
}

void MainWindow::on_button4_clicked()
{
    ui->button4->setText("X");
}

void MainWindow::on_button5_clicked()
{
    ui->button5->setText("X");
}

void MainWindow::on_button6_clicked()
{
    ui->button6->setText("X");
}

void MainWindow::on_button7_clicked()
{
    ui->button7->setText("X");
}

void MainWindow::on_button8_clicked()
{
    ui->button8->setText("X");
}

void MainWindow::on_button9_clicked()
{
    ui->button9->setText("X");
}
