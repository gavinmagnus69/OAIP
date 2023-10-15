#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vectorinitializer();
    showtables();
}
void MainWindow::vectorinitializer(){
    for(int j = 0;j<10;j++){
    vector<int> tmp1;
    vector<pair<int,double>> tmp2;
    for(int i =0;i<10;++i){
        tmp1.push_back(rand()%100);
         //qDebug()
    }

    for(int i =0;i<10;++i){
        tmp2.push_back(pair(rand()%100,(double)(rand()%100+(double)(rand())/100)));
    }
    c.push_back(pair(tmp1,tmp2));
    }
}
void MainWindow::showtables(){
    ui->t1->setRowCount(30);
    ui->t1->setColumnCount(10);
    ui->t2->setRowCount(30);
    ui->t2->setColumnCount(10);
    for(int i =0;i<10;i++){
        for (int j = 0; j < c[i].f.size(); ++j) {
                   auto *item = new QTableWidgetItem(QString::number(c[i].f[j]));
                   ui->t1->setItem(i * 3, j, item);
              }

    }
    for (int i = 0; i < c.size(); ++i) {
            for (int j = 0; j < c[i].s.size(); ++j) {
                auto *item = new QTableWidgetItem(QString::number(c[i].s[j].f));
                ui->t2->setItem(i * 3, j, item);
                item = new QTableWidgetItem(QString::number(c[i].s[j].s));
                ui->t2->setItem(3 * i + 1, j, item);
            }
        }

}
MainWindow::~MainWindow()
{
    delete ui;
}

