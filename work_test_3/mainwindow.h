#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MouseArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void refresh_label(int x, int y);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *event);
    MouseArea *mouseArea;
    QLabel *label_K, *label_M;
    QString num;
};

#endif // MAINWINDOW_H
