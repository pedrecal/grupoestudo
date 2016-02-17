#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hey = new QLabel;
    dj = new QLabel;

    hey->setBackgroundRole(QPalette::Base);
    hey->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    hey->setScaledContents(true);


    dj->setBackgroundRole(QPalette::Base);
    dj->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    dj->setScaledContents(true);

    QImage imgHey("../azul.jpg");

    QImage imgDj("../vermelho.jpg");

    hey->setPixmap(QPixmap::fromImage(imgHey));

    dj->setPixmap(QPixmap::fromImage(imgDj));

    ui->scrollHey->setWidget(hey);
    ui->scrollDj->setWidget(dj);

    ui->scrollDj->hide();
    ui->scrollHey->hide();

    connect(ui->pushHey, SIGNAL(released()), this, SLOT(piscaHey()));
    connect(ui->pushDj, SIGNAL(released()), this, SLOT(piscaDj()));

}
MainWindow::~MainWindow()
{
    delete hey;
    delete dj;
    delete ui;
}

void MainWindow::piscaHey()
{
    if(ui->scrollHey->isHidden())
        ui->scrollHey->show();
    else
        ui->scrollHey->hide();
}

void MainWindow::piscaDj()
{
    if(ui->scrollDj->isHidden())
        ui->scrollDj->show();
    else
        ui->scrollDj->hide();
}







