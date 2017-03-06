#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include "common.h"

#include "qlabel.h"
#include "qevent.h"
#include "qpainter.h"

class ImageWidget :
    public QLabel
{
public:
    ImageWidget();
    ~ImageWidget();

    bool isOn;

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);

private:
    int mouseX;
    int mouseY;
};

#endif // IMAGEWIDGET_H
