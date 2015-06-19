#ifndef CARREGAIMAGE_H
#define CARREGAIMAGE_H

#include <QLabel>
#include <QScrollArea>
#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"

class carregaImage
{
public:
    carregaImage();
    ~carregaImage();
    bool isImage;
    QLabel *image;
public slots:
    void carregar();
};

#endif // CARREGAIMAGE_H
