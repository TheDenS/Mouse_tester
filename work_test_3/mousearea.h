#ifndef MOUSEAREA_H
#define MOUSEAREA_H

#include <QWidget>
#include <QPoint>


class MouseArea : public QWidget
{
    Q_OBJECT

public:
    MouseArea(QWidget *parent = nullptr);
    QPoint getLastPoint() const {return lastPoint;}

signals:
    void mouseNew(int x, int y);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QPoint lastPoint;
};

#endif // MOUSEAREA_H
