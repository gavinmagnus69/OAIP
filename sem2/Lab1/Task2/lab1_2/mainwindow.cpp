#include "mainwindow.h"
#include "ui_mainwindow.h"

void showinfo(prod a){
    qDebug()<<a.prodtype<<" "<<a.modelname<<" "<<a.prodecode<<" "<<a.price<<" "<<a.amount;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->selectfilebutton,SIGNAL(pressed()),this,SLOT(on_selectfilebutton_clicked()));
    connect(ui->findbynamebutton,SIGNAL(pressed()),this,SLOT(on_findbynamebutton_clicked()));
    connect(ui->cancell,SIGNAL(pressed()),this,SLOT(on_cancell_clicked()));
    connect(ui->findbyamountbutton,SIGNAL(pressed()),this,SLOT(on_findbyamountbutton_clicked()));
     connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortTable(int)));
    ui->findbyamountedit->setMaximum(2228228);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sortTable(int a){
    if(file.fileName()==""){
        return;
    }
    if(a<2){
        ui->tableWidget->sortItems(a);
    }
    if(a==3){
    for(int i =0;i<50;i++){
        for(int i =0;i<=cnt2;i++){
            if(i==cnt2){
                break;
            }
            if(products[i].price>products[i+1].price){
                std::swap(products[i],products[i+1]);
            }
        }

    }
    updatetable();
    }
    if(a==2){
    for(int i =0;i<50;i++){
        for(int i =0;i<=cnt2;i++){
            if(i==cnt2){
                break;
            }
            if(products[i].prodecode>products[i+1].prodecode){
                std::swap(products[i],products[i+1]);
            }


        }

    }
    updatetable();
    }


}
void MainWindow::updatetable(){
    ui->tableWidget->setRowCount(cnt2+1);
    ui->tableWidget->setColumnCount(5);
    for(int i = 0;i<=cnt2;i++){
        //prod type
        QTableWidgetItem * itm = new QTableWidgetItem(products[i].prodtype);
        ui->tableWidget->setItem(i,0,itm);
    }
    //model name
    for(int i = 0;i<=cnt2;i++){

        QTableWidgetItem * itm = new QTableWidgetItem(products[i].modelname);
        ui->tableWidget->setItem(i,1,itm);
    }
    //prod code
    for(int i = 0;i<=cnt2;i++){

        QTableWidgetItem * itm = new QTableWidgetItem(QString::number(products[i].prodecode));
        ui->tableWidget->setItem(i,2,itm);
    }
    //price
    for(int i = 0;i<=cnt2;i++){

        QTableWidgetItem * itm = new QTableWidgetItem(QString::number(products[i].price));
        ui->tableWidget->setItem(i,3,itm);
    }
    //amount
    for(int i = 0;i<=cnt2;i++){

        QTableWidgetItem * itm = new QTableWidgetItem(QString::number(products[i].amount));
        ui->tableWidget->setItem(i,4,itm);
    }



}

void MainWindow::on_selectfilebutton_clicked()
{
 file.setFileName(QFileDialog::getOpenFileName(this, tr("Open file")));
 file.open(QIODeviceBase::ReadWrite);
 //QTextStream bruh(&file);
 QString txt = ".txt";
 QString filename = file.fileName();
 if(!filename.contains(txt)){
     return;
 }
 QString s;
 QString subs;
 int cnt =0;
 while(!file.atEnd()){
     int minicnt =0;
     subs="";
     s = file.readLine();
     s.remove(s.length()-2,2);
     s.append('$');
     for(int i = 0;i<s.length();++i){
         //int minicnt =0;

         if(s[i]==' '||s[i]=='$'){
             qDebug()<<subs;
             if(minicnt==0){
                 products[cnt].prodtype = subs;

             }
             if(minicnt ==1){
                 products[cnt].modelname = subs;
             }
             if(minicnt==2){
                 products[cnt].prodecode = subs.toInt();
             }
             if(minicnt==3){
                 products[cnt].price = subs.toInt();
             }
             if(minicnt==4){
                 products[cnt].amount = subs.toInt();
             }
             subs="";
             minicnt++;
             continue;
         }
          subs+=s[i];


     }
     qDebug()<<s<<" length = "<<s.length();

//     for(int i = 0;i<s.length();i++){
//         qDebug()<<s[i];
//     }


     cnt++;
 }
 cnt-=2;
 cnt2=cnt;
// qDebug()<<"from array";
// for(int i =0;i<=cnt;++i){
//     showinfo(products[i]);
// }

 file.close();
 updatetable();
}



void MainWindow::on_cancell_clicked()
{
    if(file.fileName()==""){
        return;
    }
    int n = ui->tableWidget->rowCount();
        for (int i = 0; i < n; i++) {
            ui->tableWidget->showRow(i);
        }
    qDebug()<<"pressed";
    updatetable();

}


void MainWindow::on_findbynamebutton_clicked()
{
    if(file.fileName()==""){
        return;
    }
    int n = ui->tableWidget->rowCount();
    QString ss = ui->lineEdit->text();
    if(ss==""){
        return;
    }
    for (int i = 0; i < n; i++) {
            QString s = ui->tableWidget->item(i, 0)->text();
            QString s1 = ui->tableWidget->item(i, 1)->text();
            if (!ss.contains(s) && !ss.contains(s1)) {
                ui->tableWidget->hideRow(i);

            }
    }

}


void MainWindow::on_findbyamountbutton_clicked()
{
    if(file.fileName()==""){
        return;
    }
    int am = ui->findbyamountedit->value();
    QString s = QString::number(am);
    if(s==""){
        return;
    }
    int n = ui->tableWidget->rowCount();
    for(int i =0;i<n;i++){
        QString sam = ui->tableWidget->item(i,4)->text();
        if(am<sam.toInt()){
            ui->tableWidget->hideRow(i);
        }

    }


}

