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

    ui->btValidacao->hide();

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

    connect(ui->btValidacao, SIGNAL(released()), this, SLOT(validacao()));
}

MainWindow::~MainWindow()
{
    delete bright;
    delete load;
    delete grayScale;
    delete ui;
}

void MainWindow::applySets()
{
    if(load->isImage == true)
    {
        light = ui->qtLuz->text().toInt(NULL);
        shadow = ui->qtSombra->text().toInt(NULL);
        bright->appling(load->isImage, light, shadow, load->image);
    }
}

void MainWindow::makeHist()
{
    if(load->isImage == true)
    {
        getScale();
        QVector<double> x(256),y(256);
        for(int i = 0; i <= 255; i++)
        {
            x[i] = i;
            y[i] = grayScale[i];

        }
        load->totalGray = 0;
        for (int i = 0; i < 256; i++)
            load->totalGray += grayScale[i];
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->replot();
        ui->btValidacao->show();
        cleanScale();
    }
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

void MainWindow::validacao()
{
    std::cout<<load->sizeImage<<" a "<<load->totalGray<<std::endl;
    if (load->totalGray == load->sizeImage)
    {
        QMessageBox::information(this, tr("Validacao"), tr("O total do histograma e de %1 pixels e a imagem tem %2 pixels. O histograma esta correto").arg(load->totalGray).arg(load->sizeImage));
        return;
    }
    else
    {
        QMessageBox::information(this, tr("Validacao"), tr("Ops, algo deu errado, a imagem e o histograma nao contem a mesma quantidade de pixels."));
        return;
    }

}
