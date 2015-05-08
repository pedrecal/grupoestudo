#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushClear_clicked()
{
    ui->lbPrint->setText(QString(""));
}


void MainWindow::on_pushOk_clicked()
{
    ui->lbPrint->setText(ui->textEnter->toPlainText());
}
