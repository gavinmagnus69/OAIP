#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mystring.h"
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


void MainWindow::on_strlenbutton_clicked()
{
    string s = ui->lineEdit->text().toStdString();
    ui->textBrowser->setText(QString::number(mstrlen(s.begin().def_it)));
}
void MainWindow::on_strcpybutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2;
    s2 = s + "1337";
    //qDebug() << s2.data();
    ui->textBrowser->setText(QString(mstrcpy(s2.data(),s.data())));
}

void MainWindow::on_strncpybutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2;
    s2 = s + "133712312312312";
    ui->textBrowser->setText(mstrncpy(s.data(),s2.data(),ui->strncpyspinbox->value()));
}


void MainWindow::on_strcatbutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2;
    s2 = s + "133712312312312";
    qDebug()<<s.data()<<" "<<s2.data()<<" "<<s.length()<<" "<<s2.length();
    ui->textBrowser->setText(QString(mstrcat(s.data(),s2.data())));
}


void MainWindow::on_strncatbutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2;
    s2 = s + "133712312312312";
    ui->textBrowser->setText(QString(mstrncat(s.data(),s2.data(),ui->strncatspinbox->value())));
}



void MainWindow::on_strcmpbutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2;
    s2 = s;
    ui->textBrowser->setText(QString::number(mstrcmp(s.data(),s2.data())));
}



void MainWindow::on_strncmpbutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2;
    s2 = "bebe";
    ui->textBrowser->setText(QString::number(mstrncmp(s.data(),s2.data(),ui->strncmpspinbox->value())));
}



void MainWindow::on_strerrbutton_clicked()
{
    ui->textBrowser->setText(QString(mstrerror(ui->strerrspinbox->value())));
}

