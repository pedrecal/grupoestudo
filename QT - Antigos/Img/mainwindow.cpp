#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QLabel>
#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Img = new QLabel;
    Img -> setBackgroundRole( QPalette::Base );
    Img -> setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    Img -> setScaledContents( true );
    ui->scrollArea-> setWidget(Img);

    ui->customplot->xAxis->setLabel("Quantity");
    ui->customplot->yAxis->setLabel("Color Grade");
    ui->customplot->xAxis->setRange(0, 300);
    ui->customplot->yAxis->setRange(0, 10000);

}

MainWindow::~MainWindow()
{
    delete Img;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());

    if ( !fileName.isEmpty() )
    {
        QImage image( fileName );

        if ( image.isNull() )
        {
            QMessageBox::information(this, tr("Image Viewer"),tr("Cannot load %1.").arg(fileName));
            return;
        }

        Img->setPixmap(QPixmap::fromImage(image));
        Img->adjustSize();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int grayScale[255] = {0}; // Shades of gray

    QImage tmpImg = Img->pixmap()->toImage();
    QColor tempColor;
    int grayColor;
    if(tmpImg.isGrayscale())
    {
        for(int i = 0; i < tmpImg.width(); i++)
        {
            for(int j = 0; j < tmpImg.height(); j++)
            {
                tempColor = tmpImg.pixel(i, j);
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
        std::cout<<x[i]<<" Quantity of pixels: "<<y[i]<<std::endl;
    }
    ui->customplot->addGraph();
    ui->customplot->QCustomPlot::setInteractions(QCP::iRangeZoom);
    ui->customplot->setInteraction(QCP::iRangeDrag, true);
    ui->customplot->graph(0)->setData(x, y);
    ui->customplot->replot();


    // To do: Set 'for' x and y, to read img and anlayze de shade
}
