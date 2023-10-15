#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include "avl.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    node<QString> * pt;
    QTreeWidgetItem* ri;
    ~MainWindow();
    QTreeWidgetItem *  addroot(QString name, QString Description);
    QTreeWidgetItem * addchild(QTreeWidgetItem * itm , QString name , QString Description);
    void fillTreeWidget(QTreeWidget *treeWidget, QTreeWidgetItem *parent, node<QString> *node);
    void fillTreeWidget2(QTreeWidgetItem* parentItem, node<QString>* treeNode);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
