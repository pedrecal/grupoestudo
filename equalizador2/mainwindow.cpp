#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollArea>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load = new carregaImage;
    bright = new brilho;
    ui->scrollArea->setWidget(load->image);
    ui->customPlot->xAxis->setLabel("Tom");
    ui->customPlot->yAxis->setLabel("Quantidade");
    ui->customPlot->xAxis->setRange(0, 255);
    ui->customPlot->yAxis->setRange(0, 1000);
    ui->customPlot->QCustomPlot::setInteractions(QCP::iRangeZoom);
    ui->customPlot->setInteraction(QCP::iRangeDrag, true);

    connect(ui->btLoad, SIGNAL(released()), load, SLOT(carregar()));

    connect(ui->btApply, SIGNAL(released()), this, SLOT(applySets()));

    connect(ui->btMakeHist, SIGNAL(released()), this, SLOT(makeHist()));
}

MainWindow::~MainWindow()
{
    delete bright->newImage;
    delete bright;
    delete load->image;
    delete load;
    delete ui;
}

void MainWindow::applySets()
{
    light = ui->qtLuz->text().toInt(NULL);
    shadow = ui->qtSombra->text().toInt(NULL);
    bright->appling(load->isImage, light, shadow, load->image);
}

void MainWindow::makeHist()
{
    QVector<double> x(256),y(256);
    for(int i = 0; i <= 255; i++)
    {
        x[i] = i;
        y[i] = bright->grayScale[i];
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->replot();
}
