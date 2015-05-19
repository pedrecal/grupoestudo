#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lbBlinkDj->hide();
    ui->lbBlinkHey->hide();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeBlink(QPushButton * button, QLabel* label)
{
    if(label->isHidden())
        connect(button, SIGNAL(clicked()), label, SLOT(show()));
    else
        connect(button, SIGNAL(clicked()), label, SLOT(hide()));
}

void MainWindow::on_pushHey_clicked()
{
    makeBlink(ui->pushHey, ui->lbBlinkHey);
}

void MainWindow::on_pushDj_clicked()
{
    makeBlink(ui->pushDj, ui->lbBlinkDj);
}
