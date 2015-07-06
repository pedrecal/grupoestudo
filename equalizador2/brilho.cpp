#include "brilho.h"

brilho::brilho(QWidget *parent) :
    QWidget(parent)
{
}
brilho::~brilho()
{
    delete newImage;
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
            for(long i = 0; i < newImage.width(); i++)
            {
                for(long j = 0; j< newImage.height(); j++)
                {
                    tempColor = newImage.pixel(i, j);
                    grayColor = (255 - tempColor.black());
                    grayColor += light;
                    grayColor -= shadow;
                    value = qRgb(grayColor, grayColor, grayColor);

                    newImage.setPixel(i, j, value);
                }
            }
        }

        image->setPixmap(QPixmap::fromImage(newImage));
    }
}
