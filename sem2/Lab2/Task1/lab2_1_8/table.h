#ifndef TABLE_H
#define TABLE_H
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "prodlist.h"
class table
{
public:
    Ui::MainWindow * mui;
    QTableWidget * tab;
    //Prodlist list;
public:
    void updatetable(Prodlist &l);
    table(){}
    void cancel(Prodlist &l);
    void deleteproduction(Prodlist &,QString);
    void find(Prodlist &,QString );
    void findbyamount(Prodlist&,QString);
    void findbyname(Prodlist&,QString);
//    table(Ui::MainWindow * b,Prodlist l){
//        mui = b;
//        //tab = t;
//        //list = l;
//    }


};

#endif // TABLE_H
