#include "mousearea.h"
#include <QtWidgets>

MouseArea::MouseArea(QWidget *parent)
    : QWidget(parent)
{
     setAttribute(Qt::WA_StaticContents);


}

void MouseArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
    }
    emit mouseNew(lastPoint.x(),lastPoint.y());
}

