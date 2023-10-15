#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <string>
#include <iostream>
//bool chkfile(QFile file1){
//    QString s = file1.readAll();
//    bool ans = 0;
//    for(int i = 0; i<=s.length();i++){
//        if(s[i]=='\n'||(s[i]>='0'&&s[i]<='9')||s[i]==' '){
//            ans = 1;

//        }
//        else{
//            ans = 0;

//        }
//    }
//    return ans;
//}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->selectfilebutton,SIGNAL(pressed()),this,SLOT(on_selectfilebutton_clicked()));
    connect(ui->bdateEdit,SIGNAL(pressed()),this,SLOT(on_bdateEdit_userDateChanged(QDate)));
    connect(ui->adddateEdit,SIGNAL(pressed()),this,SLOT(on_adddateEdit_userDateChanged(QDate)));
    connect(ui->spintable,SIGNAL(pressed()),this,SLOT(on_spintable_valueChanged(int)));
    connect(ui->changedate,SIGNAL(pressed()),this,SLOT(on_changedate_clicked()));
    QDate bebra = QDate::currentDate();
    QString s = bebra.toString("dd.MM.yyyy");
    ui->label_6->setText(s);
}
QString tost(QDate a){
    QString st;
    int dayn = a.day();
    int m = a.month();
    int y = a.year();
    st = QString::number(dayn) +"." + QString::number(m) +"."+ QString::number(y);
    return st;
}
Date toDate(QDate a){
    return Date(a.day(),a.month(),a.year());
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updatetable(){
    int cnt = 0;
    file.open(QIODevice::ReadOnly|QIODeviceBase::WriteOnly);

    QString s;
    //char ss;

    QString sline;
//    while(!file.atEnd()){

//        file.getChar(&ss);
//        //qDebug()<<ss;

//        if(ss==' '){
//            qDebug()<<s;
//         dates[cnt] = QDate::fromString(s, "d.M.yyyy");
//         cnt++;
//         s="";
//         continue;
//        }
//        s+=ss;

//    }
//    s.erase(s.cend()-2,s.cend());
//    qDebug()<<"cnt = "<<cnt<<" s = "<<s;
//    dates[cnt] = QDate::fromString(s,"d.M.yyyy");
    while(!file.atEnd()){
        s="";
        sline = file.readLine();
        qDebug()<<" line : "<<sline;
        for(int i = 0;i<=sline.length()-1;i++){

            qDebug()<<sline[i];
            if(sline[i]==' '||sline[i]=='\xd'||sline[i]=='\xa'){
//                if(sline[i]=='\xa'){
//                    continue;
//                }
                if(s.length()<7){
                    continue;
                }
                if(s.length()>10){

                    s.remove(11,s.length()-10);
                    qDebug()<<s;
                }
                qDebug()<<s<<" to array";
                dates[cnt] = QDate::fromString(s,"dd.MM.yyyy");
                cnt++;
                s="";
                continue;
            }
            s+=sline[i];
        }
    }
    cnt--;
    qDebug()<<"s ost = "<<s;
    if(s.length()>8){
        cnt++;
        qDebug()<<"case1";
        s.remove(10,s.length()-10);
    dates[cnt] = QDate::fromString(s,"dd.MM.yyyy");
    }
    cnt2 = cnt;
    qDebug()<<"cnt = "<<cnt;
    //dates[cnt] = QDate::fromString(s,"d.M.yyyy");
    for(int i = 0 ;i<=cnt;i++){
        dates2[i]=toDate(dates[i]);//from dates qdate array to dates2 array of dates for using Date methods
    }
    ui->tableWidget->setRowCount(cnt+1);
    ui->tableWidget->setColumnCount(4);
    //column of days from file
    for(int i = 0 ; i <=cnt;i++ ){
    QTableWidgetItem * itm = new QTableWidgetItem(tost(dates[i]));
    ui->tableWidget->setItem(i,0,itm);
    }
    //column of next days from file
    //qDebug()<<"next date: \n";
    for(int i = 0 ; i <=cnt;i++ ){
      //dates2[i].nextday().showinfo();
    QTableWidgetItem * itm = new QTableWidgetItem(tost(dates2[i].nextday().toQDate()));
    ui->tableWidget->setItem(i,1,itm);
    }
    //column of prev days from file
    for(int i = 0 ; i <=cnt;i++ ){
    QTableWidgetItem * itm = new QTableWidgetItem(tost(dates2[i].prevday().toQDate()));
    ui->tableWidget->setItem(i,2,itm);
    }
    //column of duration beetween days
    //QDate currentday = QDate::currentDate();
    for(int i = 0 ; i <=cnt;i++ ){
     //qDebug()<<dates2[i].duration(toDate(currentday))<<"\n";
        QTableWidgetItem * itm;
        if(i!=cnt){
    itm = new QTableWidgetItem(QString::number(dates2[i].duration(toDate(dates[i+1]))));
        }else{
           itm = new QTableWidgetItem(QString::number(dates2[i].duration(toDate(dates[0]))));

        }
    ui->tableWidget->setItem(i,3,itm);
    }


    for(int i = 0;i<=cnt;i++){
        qDebug()<<"massive";
        qDebug()<<dates[i].day()<<"."<<dates[i].month()<<"."<<dates[i].year();

    }
    //qDebug()<<bday.day()<<"..."<<bday.month()<<"..."<<bday.year();
    file.close();


}
void MainWindow::on_selectfilebutton_clicked()
{
    file.setFileName(QFileDialog::getOpenFileName(this, tr("Choose your file wisely, only .txt files supported!!!")));
    QMessageBox bruh;

    if(!file.exists()){

        bruh.setWindowTitle("ti loh");
        bruh.setInformativeText(
        "error 228"            );
        bruh.setText("this wrong i can feel it.");
        bruh.exec();
    }
    else{


      file.open(QIODeviceBase::ReadOnly);
            QString s = file.readAll();
            qDebug()<<"string::"<<s;
            bool ans;
            for(int i = 0; i<s.length();i++){
                qDebug()<<s[i];
                if(s[i]=='\r'||s[i]=='\n'||(s[i]>='0' &&s[i]<='9')||s[i]==' '||s[i]=='.'){
                    ans = 1;
                }
                else{
                    ans = 0;
                    break;

                }
            }
            if(s==""){
            ans= 1;
            }
            chk=ans;
             file.close();
          if(!ans){
               bruh.setWindowTitle("ti loh");
               bruh.setInformativeText(
                "error 228"            );
               bruh.setText("this wrong i can feel it.");
               bruh.exec();
           }
           else{

            bruh.setWindowTitle("ti ne loh");
            bruh.setText("good game well played.");
            bruh.exec();
            updatetable();
            //}
        }
    }
}
void MainWindow::on_bdateEdit_userDateChanged(const QDate &date)
{
    if(!chk){
        QMessageBox bruh;

        bruh.setWindowTitle("ti loh");
        bruh.setInformativeText(
         "error 228"            );
        bruh.setText("this wrong i can feel it.");
        bruh.exec();

    }
    bday = date;
    QDate cur = QDate::currentDate();
    Date date2 = toDate(bday);
    int n = toDate(cur).daystillmybday(date2);
    QString s = QString::number(n);
    ui->label_3->setText(s);
    updatetable();
}


void MainWindow::on_adddateEdit_userDateChanged(const QDate &date)
{
    if(!chk){
        QMessageBox bruh;

        bruh.setWindowTitle("ti loh");
        bruh.setInformativeText(
         "error 228"            );
        bruh.setText("this wrong i can feel it.");
        bruh.exec();
        return;

    }
    if(!file.exists()){
        QMessageBox bruh;
        bruh.setWindowTitle("error");
        bruh.setInformativeText(
        "error 1337"            );
        bruh.setText("please select file firstly.");

        bruh.exec();
        return;
    }
    adate = date;
}


void MainWindow::on_adddate_clicked()
{
    if(!chk){
        QMessageBox bruh;

        bruh.setWindowTitle("ti loh");
        bruh.setInformativeText(
         "error 228"            );
        bruh.setText("this wrong i can feel it.");
        bruh.exec();
        return;

    }
    //qDebug()<<adate.day()<<".|."<<adate.month()<<".|."<<adate.year();
    if(!file.exists()){
        QMessageBox bruh;
        bruh.setWindowTitle("error");
        bruh.setInformativeText(
        "error 1337"            );
        bruh.setText("please select file firstly.");

        bruh.exec();
        return;
    }
    file.open(QIODeviceBase::ReadWrite|QIODeviceBase::Append);
//    QString s1 = file.readLine();
//    int pose = s1.length();
    QTextStream stream(&file);
    //stream.seek(s1.length());
    //stream.seek(cnt2*10+cnt2);
    //stream<<" ";
    qDebug()<<" bruh "<<cnt2*10+cnt2-1;
    //stream<<" ";
    //stream.seek(0);
    stream<<adate.toString("dd.MM.yyyy");
    stream<<" ";
    //stream<<" ";
    //stream<<" ";
    file.close();
    updatetable();
}


void MainWindow::on_spintable_valueChanged(int arg1)
{
    if(!chk){
        QMessageBox bruh;

        bruh.setWindowTitle("ti loh");
        bruh.setInformativeText(
         "error 228"            );
        bruh.setText("this wrong i can feel it.");
        bruh.exec();
        return;

    }

    if(!file.exists()){
        QMessageBox bruh;
        bruh.setWindowTitle("error");
        bruh.setInformativeText(
        "error 1337"            );
        bruh.setText("please select file firstly.");

        bruh.exec();
        return;
    }
    if(arg1<1||arg1>cnt2+1){
        QMessageBox bruh;
        bruh.setWindowTitle("error");
        bruh.setInformativeText(
        "error 69"            );
        bruh.setText("choose correct row.");
        bruh.exec();
        return;
    }
 toChange = arg1;
}


void MainWindow::on_changedate_clicked()
{
    if(!chk){
        QMessageBox bruh;

        bruh.setWindowTitle("ti loh");
        bruh.setInformativeText(
         "error 228"            );
        bruh.setText("this wrong i can feel it.");
        bruh.exec();
        return;

    }
    if(!file.exists()){
        QMessageBox bruh;
        bruh.setWindowTitle("error");
        bruh.setInformativeText(
        "error 1337"            );
        bruh.setText("please select file firstly.");

        bruh.exec();
        return;
    }
    if(!toChange){
        return;
    }
    if(toChange>cnt2+1){
        return;
    }
    std::string debug;
    //QDate changedDate = adate;
    file.open(QIODeviceBase::ReadWrite|QIODeviceBase::Text);
    QString bigdebug;

    bigdebug = file.readAll();
    qDebug()<<"big debug: "<<bigdebug;
    debug = bigdebug.toStdString();
    //QString alpha = dates[toChange-1].toString("dd.MM.yyyy");
    //qDebug()<<alpha;
    //qDebug()<<"pos of incl : "<<debug.find(alpha.toStdString());
    //int posi = debug.find(alpha.toStdString());
//    for(int i = 0;i<=debug.length();i++){
//        qDebug()<<debug[i];

//    }
    //qDebug()<<debug;
    QString input = adate.toString("dd.MM.yyyy");
    QTextStream bebra(&file);
    //qDebug()<<"posi"<<posi;
    bebra.seek((toChange-1)*10+2*(toChange-1));
    //file.seek(posi);
    //file.write(input);
    bebra<<input;
    file.close();
    updatetable();
}

