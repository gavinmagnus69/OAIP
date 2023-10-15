#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    t.mui = ui;
    //t.list = l;
    ui->setupUi(this);
    ui->enteramountadd->setMinimum(1);
    ui->enterdepartmentadd->setMinimum(1);
    ui->findbyamountspin->setMinimum(1);
    //ui->deletespin->setMinimum(1);

    //connect(ui->selectfilebutton,SIGNAL(pressed()),this,SLOT(on_selectfilebutton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_selectfilebutton_clicked()
{
    if(chk){

            QMessageBox bruh;
                   bruh.setWindowTitle("ti loh");
                           bruh.setInformativeText(
                           "error 228"            );
                           bruh.setText("you are already working with a file.");
                           bruh.exec();
                   return;

    }
    file.setFileName(QFileDialog::getOpenFileName(this, tr("Open file")));
    chk = f.fromfile(file,l);
    if(chk){
        qDebug()<<" here";
        t.updatetable(l);
    }
    else{
        return ;
    }
}


void MainWindow::on_addprodbutton_clicked()
{
    if(!chk){
        return;
    }
    if(ui->enternameadd->text()==""||ui->enteramountadd->text()==""||ui->enterdepartmentadd->text()==""){
        return;
    }
    Production temp(ui->enternameadd->text(),ui->enteramountadd->text(),ui->enterdepartmentadd->text());
    l.push_back(temp);
    t.updatetable(l);
}




void MainWindow::on_deleteprodbutton_clicked()
{
    qDebug()<<"delete clicked";
    if(!chk){
        return;
    }
    t.deleteproduction(l,ui->deleteprodtext->text());
}


void MainWindow::on_rewritefilebutton_clicked()
{
    if(!chk){
        return;
    }
    f.tofile(file,l);
}
void MainWindow::on_finddepbutton_clicked(){
    if(!chk){
        return;
    }
    t.find(l,ui->finddepspin->text());
}
void MainWindow::on_cancelbutton_clicked()
{
    t.cancel(l);
}
void MainWindow::on_findbyamount_clicked()
{
    if(!chk){
        return;
    }
    t.findbyamount(l,ui->findbyamountspin->text());
}
void MainWindow::on_findbynamebutton_clicked(){
    if(!chk){
        return;
    }
    t.findbyname(l,ui->findbyname->text());
}



