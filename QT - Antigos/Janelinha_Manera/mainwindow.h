#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushClear_clicked();

    void on_pushOk_clicked();

    void on_textEnter_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
