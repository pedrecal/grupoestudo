#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void makeBlink(QPushButton* , QLabel*);
private slots:
    void on_pushHey_clicked();
    void on_pushDj_clicked();

public slots:


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
