#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load = new carregaImage;
    ui->scrollArea->setWidget(load->image);

    connect(ui->btLoad, SIGNAL(released()), load, SLOT(carregar()));
}

MainWindow::~MainWindow()
{
    delete load;
    delete ui;
}
