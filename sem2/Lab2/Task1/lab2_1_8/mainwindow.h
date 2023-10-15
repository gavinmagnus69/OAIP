#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "prodlist.h"
#include <QMessageBox>
#include <QFileDialog>
#include "filework.h"
#include "table.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QFile file;
    FileWork f;
    Prodlist l;
    table t;
    bool chk = 0;
    MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *ui;

    ~MainWindow();

private slots:
    void on_selectfilebutton_clicked();

    void on_addprodbutton_clicked();

    void on_deleteprodbutton_clicked();
    void on_rewritefilebutton_clicked();
    void on_finddepbutton_clicked();
    void on_cancelbutton_clicked();
    void on_findbyamount_clicked();
    void on_findbynamebutton_clicked();
};
#endif // MAINWINDOW_H
