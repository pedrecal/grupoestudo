#ifndef CARREGAIMAGE_H
#define CARREGAIMAGE_H

#include <QWidget>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>

class carregaImage : public QWidget
{
    Q_OBJECT
public:
    explicit carregaImage(QWidget *parent = 0);
    QLabel *image;
    bool isImage;

signals:

public slots:
    void carregar();

};

#endif // CARREGAIMAGE_H
