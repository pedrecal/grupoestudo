#include "mainwindow.h"
#include "ui_mainwindow.h"
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


    ui->lbPrint->clear();
}


void MainWindow::on_pushOk_clicked()
{

    QString teste;

    teste = ui->textEnter->text();

    ui->lbPrint->setText(teste);

    ui->textEnter->clear();

    //ui->lbPrint->setText(ui->textEnter->text());
    //ui->textEnter->clear();
}
