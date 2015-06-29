#include "brilho.h"

brilho::brilho(QWidget *parent) :
    QWidget(parent)
{
    grayScale = new int[256];
    for (int i = 0; i<256; i++)
        grayScale[i] = 0;
}
void brilho::appling(bool isImage, int light, int shadow, QLabel *image)
{
    if(isImage)
    {

        QImage newImage = image->pixmap()->toImage();
        QColor tempColor;
        int grayColor = 0;
        QRgb value;
        if(newImage.isGrayscale())
        {
            for(int i = 0; i < newImage.width(); i++)
            {
                for(int j = 0; j< newImage.height(); j++)
                {
                    tempColor = newImage.pixel(i, j);
                    grayColor = (255 - tempColor.black());
                    grayColor += light;
                    grayColor -= shadow;
                    grayScale[grayColor]++;
                    value = qRgb(grayColor, grayColor, grayColor);

                    newImage.setPixel(i, j, value);
                }
            }
        }

        image->setPixmap(QPixmap::fromImage(newImage));
    }
}
