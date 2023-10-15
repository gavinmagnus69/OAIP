#include "mainwindow.h"
//#include "qcustomplot.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    QElapsedTimer timer;
    ui->setupUi(this);
    my_hashtable * t16 = new my_hashtable(16);
    QVector<my_pair> t16vec(16);
    QVector<double> time16(16);

    for(int i = 0; i < 16; ++i){
        t16vec[i] = my_pair(rand(), rand());
        t16->insert(t16vec[i]);
    }
    my_hashtable * t64 = new my_hashtable(64);
    QVector<my_pair> t64vec(64);
    QVector<double> time64(64);
    for(int i = 0; i < 64; ++i){
        t64vec[i] = my_pair(rand(), rand());
        t64->insert(t64vec[i]);
    }
    my_hashtable * t128 = new my_hashtable(128);
    QVector<my_pair> t128vec(128);
    QVector<double> time128(128);
    for(int i = 0; i < 128; ++i){
        t128vec[i] = my_pair(rand(), rand());
        t128->insert(t128vec[i]);
    }
    my_hashtable * t2048 = new my_hashtable(2048);
    QVector<my_pair> t2048vec(2048);
    QVector<double> time2048(2048);
    for(int i = 0; i < 2048; ++i){
        t2048vec[i] = my_pair(rand(), rand());
        t2048->insert(t2048vec[i]);
    }


    QVector<double> size16(16);
    for(int i = 0 ; i < 16; ++i){
        size16.push_back(i + 1);
       timer.start();
        t16->find(t16vec[i].key);
        time16.push_back(timer.nsecsElapsed());
         timer.restart();
    }
    QVector<double> size64(64);
    for(int i = 0 ; i < 64; ++i){
        size64.push_back(i + 1);
       timer.start();
        t64->find(t64vec[i].key);
        time64.push_back(timer.nsecsElapsed());
         timer.restart();
    }
    QVector<double> size128(128);
    for(int i = 0 ; i < 128; ++i){
        size128.push_back(i + 1);
       timer.start();
        t128->find(t128vec[i].key);
        time128.push_back(timer.nsecsElapsed());
         timer.restart();
    }
    QVector<double> size2048(2048);
    for(int i = 0 ; i < 2048; ++i){
        size2048.push_back(i + 1);
       timer.start();
        t2048->find(t2048vec[i].key);
        time2048.push_back(timer.nsecsElapsed());
         timer.restart();
    }














    QCPGraph * graph = ui->widget->addGraph();
    QCPGraph * graph2 = ui->widget_2->addGraph();
    QCPGraph * graph3 = ui->widget_3->addGraph();
    QCPGraph * graph4 = ui->widget_4->addGraph();
    QVector<double> xData={1,2,3,4,5,6,7,9,10}, yData{2,4,6,8,10,12,14,16,18,20};


    graph->setData(size16, time16);
    graph2->setData(size64, time64);
    graph3->setData(size128, time128);
    graph4->setData(size2048, time2048);

    ui->widget->rescaleAxes();
    ui->widget_2->rescaleAxes();
    ui->widget_3->rescaleAxes();
    ui->widget_4->rescaleAxes();// автоматическое масштабировани осей

    ui->widget->replot();
    ui->widget_2->replot();
    ui->widget_3->replot();
    ui->widget_4->replot();// обновление графика
}

MainWindow::~MainWindow()
{
    delete ui;
}

