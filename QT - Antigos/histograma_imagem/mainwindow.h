#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void loadImage();
    void makeHist();

private:
    Ui::MainWindow *ui;
    QLabel *imgEnter;
    bool isImage;

};

#endif // MAINWINDOW_H
