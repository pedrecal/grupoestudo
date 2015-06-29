#ifndef BRILHO_H
#define BRILHO_H

#include <QWidget>
#include <QLabel>

class brilho : public QWidget
{
    Q_OBJECT
public:
    explicit brilho(QWidget *parent = 0);
    QImage *newImage;
    void appling(bool, int, int, QLabel *);
    int *grayScale;
signals:

public slots:

};

#endif // BRILHO_H
