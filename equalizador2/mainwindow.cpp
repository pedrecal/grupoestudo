#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load = new carregaImage;
    //connect(ui->btLoad, SIGNAL(released()), this, SLOT(load->carregar()));
}

MainWindow::~MainWindow()
{
    delete load;
    delete ui;
}
