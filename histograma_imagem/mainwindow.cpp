#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QLabel>
#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imgEnter = new QLabel;
    imgEnter -> setBackgroundRole(QPalette::Base);
    imgEnter -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imgEnter -> setScaledContents(true);
    ui->widImg->setWidget(imgEnter);


    ui->customPlot->xAxis->setLabel("Tom");
    ui->customPlot->yAxis->setLabel("Quantidade");
    ui->customPlot->xAxis->setRange(0, 255);
    ui->customPlot->yAxis->setRange(0, 1000);

    isImage = false;

    connect(ui->btLoad, SIGNAL(released()), this, SLOT(loadImage()));
    connect(ui->btOk, SIGNAL(released()), this, SLOT(makeHist()));

}

MainWindow::~MainWindow()
{
    delete imgEnter;
    delete ui;
}

void MainWindow::loadImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),QDir::currentPath());

    if (!fileName.isEmpty())
    {
        QImage image(fileName);
        if (image.isNull())
        {
            QMessageBox::information(this, tr("Image Viewer"), tr("Cannot Load %1").arg(fileName));
            return;
        }

        imgEnter->setPixmap(QPixmap::fromImage(image));
        imgEnter->adjustSize();

        isImage = true;
    }

}

void MainWindow::makeHist()
{
    if(isImage)
    {
        int grayScale[255] = {0};
        QImage image = imgEnter->pixmap()->toImage();
        QColor tempColor;
        int grayColor;
        if(image.isGrayscale())
        {
            for(int i = 0; i < image.width(); i++)
            {
                for(int j = 0; j < image.height(); j++)
                {
                    tempColor = image.pixel(i, j);
                    grayColor = (255 - tempColor.black());
                    grayScale[grayColor]++;
                }
            }
        }
        QVector<double> x(255),y(255);
        for(int i = 0; i < 255; i++)
        {
            x[i] = i;
            y[i] = grayScale[i];
        }
        ui->customPlot->addGraph();
        ui->customPlot->QCustomPlot::setInteractions(QCP::iRangeZoom);
        ui->customPlot->setInteraction(QCP::iRangeDrag, true);
        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->replot();
    }
    else
    {
        QMessageBox::information(this, tr("Erro"), tr("Carregue uma imagem antes"));
    }

}
