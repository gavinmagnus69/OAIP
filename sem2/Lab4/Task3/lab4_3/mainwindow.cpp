#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parse.h"
#include <QFile>
#include <QFileDialog>
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


void MainWindow::on_parsebutton_clicked()
{
    qDebug() << ui->lineEdit->text();
    QString mytext = ui->lineEdit->text();
    ui->tb1->setText(searching_for_vars(ui->lineEdit->text()));
    ui->tb2->setText(searching_for_localvars(mytext));
    ui->tb3->setText(searching_for_changes(mytext));
    ui->tb4->setText(searching_for_errors(mytext));
    ui->tb5->setText(searching_for_funprots(mytext));
    ui->tb6->setText(searching_for_redef_fun(mytext));
    ui->tb7->setText(search_for_depth(mytext));
}


void MainWindow::on_choosefilebutton_clicked()
{
    QFile file1;
    file1.setFileName(QFileDialog::getOpenFileName(this, tr("Open file")));
    file1.open(QIODeviceBase::ReadWrite);
    QString mytext =file1.readAll();
    qDebug() << mytext;
    ui->tb1->setText(searching_for_vars(ui->lineEdit->text()));
    ui->tb2->setText(searching_for_localvars(mytext));
    ui->tb3->setText(searching_for_changes(mytext));
    ui->tb4->setText(searching_for_errors(mytext));
    ui->tb5->setText(searching_for_funprots(mytext));
    ui->tb6->setText(searching_for_redef_fun(mytext));
    ui->tb7->setText(search_for_depth(mytext));
}

