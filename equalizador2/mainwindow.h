#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "carregaimage.h"
#include "brilho.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    carregaImage *load;
    brilho *bright;
    int light;
    int shadow;
    void getScale();
    void cleanScale();
    int *grayScale;
private:
    Ui::MainWindow *ui;
public slots:
    void applySets();
    void makeHist();
};

#endif // MAINWINDOW_H
