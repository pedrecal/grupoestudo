#include <iostream>

#include <QtGui>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget *parent ):QMainWindow(parent), ui( new Ui::MainWindow )
{
    ui->setupUi(this);

    clp = new conceitosLinguagemProgramacao();

    imageOriginal = new QLabel;
    imageOriginal -> setBackgroundRole( QPalette::Base );
    imageOriginal -> setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    imageOriginal -> setScaledContents( true );
    ui->scrOriginal -> setWidget( imageOriginal );

    imageProcessada = new QLabel;
    imageProcessada -> setBackgroundRole( QPalette::Base );
    imageProcessada -> setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    imageProcessada -> setScaledContents( true );
    ui->scrProcessada -> setWidget( imageProcessada );

    imageTeste = new QLabel;
    imageTeste -> setBackgroundRole( QPalette::Base );
    imageTeste -> setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    imageTeste -> setScaledContents( true );
    ui->scrTeste -> setWidget( imageTeste );

    isImage = false;

    connect( ui->btnStart, SIGNAL( released() ), this, SLOT( slotPerformTest() ));
    connect( ui->btnLoad, SIGNAL( released() ), this, SLOT( slotLoadImagem() ));
    connect( ui->btnProcessa, SIGNAL( released() ), this, SLOT( slotProcessaImagem() ));

    connect( ui->btnTeste, SIGNAL( released() ), this, SLOT( slotTeste() ));

    timer.start();
}

MainWindow::~MainWindow()
{
    delete clp;
    delete imageOriginal;
    delete imageProcessada;
    delete imageTeste;
    delete ui;
}

void MainWindow::slotPerformTest()
{
    const int tValue = 10000;

    timer.restart();
    std::cout << clp->setVetor( tValue * tValue ) << "\t";
    std::cout << "setVetor    \t" << timer.elapsed() << " milliseconds" << std::endl;

    timer.restart();
    std::cout << clp->setPonteiro( tValue * tValue ) << "\t";
    std::cout << "setPonteiro \t" << timer.elapsed() << " milliseconds" << std::endl;

    timer.restart();
    std::cout << clp->setMatriz( tValue, tValue ) << "\t";
    std::cout << "setMatriz   \t" << timer.elapsed() << " milliseconds" << std::endl;

    timer.restart();
    std::cout << clp->setMatrizErr( tValue, tValue ) << "\t";
    std::cout << "setMatrizErr \t" << timer.elapsed() << " milliseconds" << std::endl;
    std::cout << std::endl;
}

void MainWindow::slotLoadImagem()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());

    if ( !fileName.isEmpty() ) {
        QImage image( fileName );
        if ( image.isNull() ) {
            QMessageBox::information(this, tr("Image Viewer"),tr("Cannot load %1.").arg(fileName));
            return;
        }

        imageOriginal -> setPixmap( QPixmap::fromImage( image ) );
        imageOriginal -> adjustSize();

        imageProcessada -> setPixmap( QPixmap::fromImage(image) );
        imageProcessada -> adjustSize();

        imageTeste -> setPixmap( QPixmap::fromImage(image) );
        imageTeste -> adjustSize();

        isImage = true;
    }
}

void MainWindow::slotProcessaImagem()
{
    if ( isImage )
    {
        QImage tmpImage = imageOriginal -> pixmap() -> toImage();
        QColor tmpColor;
        int grayColor = 0;
        QRgb value;

        if ( tmpImage.isGrayscale() ) {
            for ( int i = 0; i < tmpImage.width(); i++ ) {
                for ( int j = 0; j < tmpImage.height(); j++ ) {
                    tmpColor = tmpImage.pixel( i, j );
                    grayColor = ( 255 - tmpColor.black() );

                    if ( grayColor < 100 )
                        grayColor = 255;

                    value = qRgb( grayColor, grayColor, grayColor );
                    tmpImage.setPixel( i, j, value );
                }
            }

            imageProcessada -> setPixmap( QPixmap::fromImage( tmpImage ) );
        }
    }
}
void MainWindow::slotTeste()
{
    std::cout<<"teste"<<std::endl;
}

