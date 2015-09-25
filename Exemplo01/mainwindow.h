#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QLabel>
#include <QScrollArea>

#include "conceitoslinguagemprogramacao.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    conceitosLinguagemProgramacao *clp;
    QElapsedTimer timer;

    QLabel *imageOriginal;
    QLabel *imageProcessada;
    QLabel *imageTeste;
    bool isImage;


public slots:
    void slotPerformTest();
    void slotLoadImagem();
    void slotProcessaImagem();
     void slotTeste();

};

#endif // MAINWINDOW_H
