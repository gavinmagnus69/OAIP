#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linkedlist.h"
#include "opz.h"
#include "linkedlist2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    linkedlist l1;
    linkedlist2 l2;
    opz o;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculatebutton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
