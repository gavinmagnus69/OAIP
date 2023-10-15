#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include "prod.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int cnt2;
    prod * products = new prod[100];
    QFile file;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updatetable();

public slots:
    void on_selectfilebutton_clicked();

    void on_cancell_clicked();

    void on_findbynamebutton_clicked();

    void on_findbyamountbutton_clicked();
    void sortTable(int);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
