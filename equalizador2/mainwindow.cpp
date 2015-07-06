#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollArea>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load = new carregaImage;
    bright = new brilho;

    grayScale = new int[256];
    cleanScale();

    ui->scrollArea->setWidget(load->image);
    ui->customPlot->xAxis->setLabel("Tom");
    ui->customPlot->yAxis->setLabel("Quantidade");
    ui->customPlot->xAxis->setRange(0, 255);
    ui->customPlot->yAxis->setRange(0, 1000);


    connect(ui->btLoad, SIGNAL(released()), load, SLOT(carregar()));

    connect(ui->btApply, SIGNAL(released()), this, SLOT(applySets()));

    connect(ui->btMakeHist, SIGNAL(released()), this, SLOT(makeHist()));
}

MainWindow::~MainWindow()
{
    delete bright;
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
    getScale();
    QVector<double> x(256),y(256);
    for(int i = 0; i <= 255; i++)
    {
        x[i] = i;
        y[i] = grayScale[i];

    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->QCustomPlot::setInteractions(QCP::iRangeZoom);
    ui->customPlot->setInteraction(QCP::iRangeDrag, true);
    ui->customPlot->replot();
    cleanScale();
}

void MainWindow::getScale()
{
    QImage tempImage = load->image->pixmap()->toImage();
    QColor tempColor;
    int grayColor;
    if(tempImage.isGrayscale())
    {
        for(int i = 0; i < tempImage.width(); i++)
        {
            for(int j = 0; j < tempImage.height(); j++)
            {
                tempColor = tempImage.pixel(i, j);
                grayColor = (255 - tempColor.black());
                grayScale[grayColor]++;
            }
        }
    }
}

void MainWindow::cleanScale()
{
    for (int i = 0; i < 256; i++)
        grayScale[i] = 0;
}
