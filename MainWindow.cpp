#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button1_clicked()
{
    ui->button1->setText("Clicked");
}

void MainWindow::on_button2_clicked()
{
    ui->button2->setText("Clicked");
}

void MainWindow::on_button3_clicked()
{
    ui->button3->setText("Clicked");
}

void MainWindow::on_button4_clicked()
{
    ui->button4->setText("Clicked");
}

void MainWindow::on_button5_clicked()
{
    ui->button5->setText("Clicked");
}

void MainWindow::on_button6_clicked()
{
    ui->button6->setText("Clicked");
}

void MainWindow::on_button7_clicked()
{
    ui->button7->setText("Clicked");
}

void MainWindow::on_button8_clicked()
{
    ui->button8->setText("Clicked");
}

void MainWindow::on_button9_clicked()
{
    ui->button9->setText("Clicked");
}
