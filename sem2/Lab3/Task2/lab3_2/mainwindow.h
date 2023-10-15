#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vector.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    vector< pair<vector<int>, vector<pair<int,double>> >> c;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void vectorinitializer();
    void showtables();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
