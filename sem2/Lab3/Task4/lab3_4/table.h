#ifndef TABLE_H
#define TABLE_H
//#include "mainwindow.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "vector.h"
#include <QString>
class table
{
    Ui::MainWindow * mui;
    vector<int> bebra;
public:
    //table(vector<int> tmp): bebra(tmp){}
    table(){}
    void getvector(const vector<int> tmp){
        bebra = tmp;
    }
    void getui(Ui::MainWindow * u){
        mui = u;
    }
    void updatetable(){
        qDebug()<<bebra.size()<<" "<<bebra.capacity();
        mui->vectortable->setColumnCount(bebra.size());
        mui->vectortable->setRowCount(2);
        for(int i =0;i<bebra.size();++i){
            QTableWidgetItem * itm = new QTableWidgetItem(QString::number(bebra[i]));
            QTableWidgetItem * itm2 = new QTableWidgetItem(QString::number(i));
            mui->vectortable->setItem(0,i,itm2);
            mui->vectortable->setItem(1,i,itm);
        }
    }
    void pushback(int tmp){
        bebra.push_back(tmp);
        updatetable();
    }
    void res(int r){
        bebra.resize(r);
        updatetable();
    }
    void showat(int tmp){
        mui->showtext->setText(QString::number(bebra[tmp]));
    }
    void backshow(){
        mui->showtext->setText(QString::number(bebra[bebra.size()-1]));
    }
    void beginshow(){
        mui->showtext->setText(QString::number(bebra[0]));
    }
    void showcap(){
        mui->showtext->setText(QString::number(bebra.capacity()));
    }
    void clearpressed(){
        bebra.clear();
        updatetable();
    }
    void isempty(){
        QString s= "";
        if(bebra.empty()){
            s = "empty";
        }
        else{
            s = "not empty";
        }
        mui->showtext->setText(s);
    }
    void erasepressed(int tmp){
        bebra.erase(tmp);
        updatetable();
    }
    void pbpressed(){
        bebra.pop_back();
        updatetable();
    }
    void sizepressed(){
        mui->showtext->setText(QString::number(bebra.size()));
    }
    void insertpressed(int pos, int tmp){
        bebra.insert(pos,tmp);
        updatetable();
    }

private slots:

    void on_backbutton_clicked();
    void on_beginbutton_clicked();
    void on_capacitybutton_clicked();






};

#endif // TABLE_H
