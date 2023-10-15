#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
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


void MainWindow::on_pushButton_clicked()
{
    int error;
    qDebug()<<"clicked";
    QString s = ui->lineEdit->text();
    qDebug()<<s<<" "<<s.length();
    dot temp;
    if(l.head==nullptr){
        qDebug()<<"yes";
    }
    for(int i =0;i<s.length();i++){
        qDebug()<<s[i];
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            qDebug()<<"default case";
            temp.index = i;
            temp.t = s[i];
            l.pushfront(temp);
        }
        if(s[i]==')'||s[i]=='}'||s[i]==']'){
            qDebug()<<"undc";
            if(l.head == nullptr){
                qDebug()<<"nullptr";
                qDebug()<<i;
                error =i;
                QMessageBox bruh;
                bruh.setWindowTitle("answer");
                        bruh.setInformativeText(
                        "failed"            );
                        bruh.setText(QString::number(error));
                        bruh.exec();
                return;
            }
            else{
                QChar r ;
                if(s[i]==')'){
                    r = '(';
                }
                if(s[i]=='}'){
                    r = '{';
                }
                if(s[i]==']'){
                    r = '[';
                }
                qDebug()<<"reverse - "<<r;
                if(r == l.head->d.t){


                   l.pop_front();
                   qDebug()<<"poped";
                   continue;
                }
                else{
                    qDebug()<<"not matched";
                    qDebug()<<i;
                    error = i;
                    QMessageBox bruh;
                    bruh.setWindowTitle("answer");
                            bruh.setInformativeText(
                            "failed"            );
                            bruh.setText(QString::number(error));
                            bruh.exec();
                    return;

                }




            }
        }
        else{
            continue;
        }
        //qDebug()<<l.head->d.t;











}
    if(l.head==nullptr){
    qDebug()<<"success";
    QMessageBox bruh;
    bruh.setWindowTitle("success");
            bruh.setInformativeText(
            "success"            );
            bruh.setText("success");
            bruh.exec();

    return;
    }
    qDebug()<<l.tail->d.index;
    QMessageBox bruh;
    bruh.setWindowTitle("answer");
            bruh.setInformativeText(
            "failed"            );
            bruh.setText(QString::number(l.tail->d.index));
            bruh.exec();

}


void MainWindow::on_selectfilebutton_clicked()
{
    QFile file;
    file.setFileName(QFileDialog::getOpenFileName(this, tr("Open file")));
    file.open(QIODeviceBase::ReadWrite);
    QString txt = ".txt";
    QString filename = file.fileName();
    qDebug()<<filename;
    if(!filename.contains(txt)){
        QMessageBox bruh;
        bruh.setWindowTitle("ti loh");
                bruh.setInformativeText(
                "error 228"            );
                bruh.setText("this wrong i can feel it.");
                bruh.exec();
        return ;
    }
    if(filename == ""){
        QMessageBox bruh;
        bruh.setWindowTitle("ti loh");
                bruh.setInformativeText(
                "error 228"            );
                bruh.setText("this wrong i can feel it.");
                bruh.exec();
        return ;
    }
    QString s = file.readLine();
    qDebug()<<s;

    int error;
    qDebug()<<"clicked";
    //QString s = ui->lineEdit->text();
    dot temp;
    if(l.head==nullptr){
        qDebug()<<"yes";
    }
    for(int i =0;i<s.length()-1;i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            qDebug()<<"default case";
            temp.index = i;
            temp.t = s[i];
            l.pushfront(temp);
        }
        if(s[i]==')'||s[i]=='}'||s[i]==']'){
            qDebug()<<"undc";
            if(l.head == nullptr){
                qDebug()<<"nullptr";
                qDebug()<<i;
                error =i;
                QMessageBox bruh;
                bruh.setWindowTitle("answer");
                        bruh.setInformativeText(
                        "failed"            );
                        bruh.setText(QString::number(error));
                        bruh.exec();
                return;
            }
            else{
                QChar r ;
                if(s[i]==')'){
                    r = '(';
                }
                if(s[i]=='}'){
                    r = '{';
                }
                if(s[i]==']'){
                    r = '[';
                }
                qDebug()<<"reverse - "<<r;
                if(r == l.head->d.t){


                   l.pop_front();
                   qDebug()<<"poped";
                   continue;
                }
                else{
                    qDebug()<<"not matched";
                    qDebug()<<i;
                    error = i;
                    QMessageBox bruh;
                    bruh.setWindowTitle("answer");
                            bruh.setInformativeText(
                            "failed"            );
                            bruh.setText(QString::number(error));
                            bruh.exec();
                    return;

                }




            }
        }
        //qDebug()<<l.head->d.t;











}
    if(l.head==nullptr){
    qDebug()<<"success";
    QMessageBox bruh;
    bruh.setWindowTitle("success");
            bruh.setInformativeText(
            "success"            );
            bruh.setText("success");
            bruh.exec();

    return;
    }
    qDebug()<<l.tail->d.index;
    QMessageBox bruh;
    bruh.setWindowTitle("answer");
            bruh.setInformativeText(
            "failed"            );
            bruh.setText(QString::number(l.tail->d.index));
            bruh.exec();
}

