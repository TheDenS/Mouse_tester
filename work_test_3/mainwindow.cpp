#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <mousearea.h>
#include <QLabel>
#include <QString>
#include <QHBoxLayout>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMinimumSize(500, 500);
    setMaximumSize(500, 500);
    setWindowTitle(tr("Xs and Os"));

    mouseArea = new MouseArea(this);
    mouseArea->setGeometry(0,30,500,470);
    mouseArea->setStyleSheet("border : 1px solid black");


    num=" ";

    label_K = new QLabel("Number pressed [" + num + "]",this);
    label_K->setGeometry(0,10,250,20);
    label_K->setStyleSheet("border : 1px solid black");
    QString pointText;

    label_M = new QLabel("Mouse clicked: X :"+pointText.setNum(mouseArea->getLastPoint().x())+" Y: "+ pointText.setNum(mouseArea->getLastPoint().y()),this);
    label_M->setGeometry(250,10,250,20);
    label_M->setStyleSheet("border : 1px solid black");

    QHBoxLayout * hlayout = new QHBoxLayout;
    hlayout->addWidget(label_K);
    hlayout->addWidget(label_M);

    hlayout->addWidget(mouseArea);
    setLayout(hlayout);

    connect(mouseArea,&MouseArea::mouseNew,this,&MainWindow::refresh_label);


}

void MainWindow::refresh_label(int x, int y)
{
    QString X,Y;
    X.setNum(x);
    Y.setNum(y);

    label_M->setText("Mouse clicked: X :" + X + " Y: "+ Y);
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch (event->key())
    {
    case Qt::Key_0:
        num='0';
        break;
    case Qt::Key_1:
        num='1';
        break;
    case Qt::Key_2:
        num='2';
        break;
    case Qt::Key_3:
        num='3';
        break;
    case Qt::Key_4:
        num='4';
        break;
    case Qt::Key_5:
        num='5';
        break;
    case Qt::Key_6:
        num='6';
        break;
    case Qt::Key_7:
        num='7';
        break;
    case Qt::Key_8:
        num='8';
        break;
    case Qt::Key_9:
        num='9';
        break;
    default:
        break;
    }
    label_K->setText("Number pressed [" + num + "]");
}

MainWindow::~MainWindow()
{
    delete ui;
}
