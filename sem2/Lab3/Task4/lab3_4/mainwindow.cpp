#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    t.getvector(tmp);
    ui->setupUi(this);
    t.getui(ui);
    t.updatetable();
}
void MainWindow::on_push_backbutton_clicked()
{
   t.pushback(ui->push_backspinbox->value());
}
void MainWindow::on_resizebutton_clicked()
{
    t.res(ui->resizespinbox->value());
}
void MainWindow::on_atbutton_clicked()
{
    t.showat(ui->atspinbox->value());
}
void MainWindow::on_backbutton_clicked()
{
    t.backshow();
}
void MainWindow::on_beginbutton_clicked()
{
    t.beginshow();

}
void MainWindow::on_capacitybutton_clicked()
{
    t.showcap();
}
void MainWindow::on_clearbutton_clicked()
{
    t.clearpressed();
}
void MainWindow::on_emptubutton_clicked()
{
    t.isempty();
}
void MainWindow::on_erasebutton_clicked()
{
    t.erasepressed(ui->erasespinbox->value());
}
void MainWindow::on_pop_backbutton_clicked()
{
    t.pbpressed();
}
void MainWindow::on_sizebutton_clicked()
{
    t.sizepressed();
}
void MainWindow::on_insertbutton_clicked()
{
    t.insertpressed(ui->insertindex->value(),ui->insertvalue->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

