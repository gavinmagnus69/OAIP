#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calculatebutton_clicked()
{
    linkedlist l11;
    QString s = ui->edit->text();
    QString opz = o.toopz(s,l1);
    qDebug()<<opz;
    qDebug()<<ui->aenter->text().toDouble()<< " "<< ui->benter->text().toDouble()<<" "<<ui->center->text().toDouble()<<" "<<ui->denter->text().toDouble()<<" "<<ui->eenter->text().toDouble();
    double ans = o.calculator(opz,l11,l2,ui->aenter->text().toDouble(),ui->benter->text().toDouble(),ui->center->text().toDouble(),ui->denter->text().toDouble(),ui->eenter->text().toDouble());
    ui->opzshow->setText(opz);
    ui->answershow->setText(QString::number(ans));

}

