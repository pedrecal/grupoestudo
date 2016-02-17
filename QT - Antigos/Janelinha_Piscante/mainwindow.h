#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLabel *hey;
    QLabel *dj;

public slots:
    void piscaDj();
    void piscaHey();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
