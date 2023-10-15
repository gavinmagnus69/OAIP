#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree<QString> t;
       QString s = "";
       int ran = 0;
       ran = abs(rand()%1000);
       qDebug() << ran;
       node<QString> * p = t.insert(nullptr , ran , "nigga");
       for(int i = 0 ; i < 100; ++i){
           ran = abs(rand()%1000);

           qDebug() << ran;

           s = QString::number(rand() % 10000);

           p = t.insert(p ,ran , s);

       }
       p = t.insert(p, 1000, "pepsi");
       p = t.insert(p, 1001, "pepsi");
       p = t.insert(p, 1002, "pepsi");
       p = t.insert(p, 1003, "pepsi");
       pt = p;
//       QTreeWidgetItem* rootItem = new QTreeWidgetItem(ui->treeWidget);
//       ri = rootItem;
//           rootItem->setText(0, "Mein tree");
       fillTreeWidget(ui->treeWidget, nullptr, p);
       //fillTreeWidget2(rootItem, pt);

    //ui->treeWidget->setColumnCount(2);
//    QTreeWidgetItem * itm = addroot("roma", "bro");
//    QTreeWidgetItem * i = addchild(itm , "asd", "asdads");
//    i =  addchild(i , "as123d", "asdads");
//    addchild(itm, "soda", "obamna");
//    i = nullptr;
}
//    QTreeWidgetItem * MainWindow::addroot(QString name, QString Description){
//    QTreeWidgetItem * itm = new QTreeWidgetItem(ui->treeWidget);
//    itm->setText(0, name);
//    itm->setText(1, Description);
//    //ui->treeWidget->addTopLevelItem(itm);
//    return itm;


//}
//QTreeWidgetItem * MainWindow::addchild(QTreeWidgetItem * parent , QString name , QString Description){
//    QTreeWidgetItem * itm = new QTreeWidgetItem(parent);
//    itm->setText(0, name);
//    itm->setText(1, Description);
//    //parent->addChild(itm);
//    return itm;



void MainWindow::fillTreeWidget(QTreeWidget *treeWidget, QTreeWidgetItem *parent, node<QString> *node) {
    if (!node)
        return;

    QStringList itemData;
    QString ans = QString::number(node->key) +" " + node->obj;
    itemData << ans;
    QTreeWidgetItem *item;
    if (parent)
        item = new QTreeWidgetItem(parent, itemData);
    else
        item = new QTreeWidgetItem(treeWidget, itemData);

    fillTreeWidget(treeWidget, item, node->left);
    fillTreeWidget(treeWidget, item, node->right);
}
void MainWindow::fillTreeWidget2(QTreeWidgetItem* parentItem, node<QString>* treeNode) {
    if (treeNode == nullptr)
        return;

    // Создаем элемент для текущего узла
    QTreeWidgetItem* item = new QTreeWidgetItem(parentItem);
    QString ans = QString::number(treeNode->key) +" " + treeNode->obj;
    item->setText(0, ans);

    // Рекурсивно заполняем левое поддерево
    fillTreeWidget2(item, treeNode->left);

    // Рекурсивно заполняем правое поддерево
    fillTreeWidget2(item, treeNode->right);
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Solve s(pt);
    ui->treeWidget->clear();
    //QTreeWidgetItem* rootItem = new QTreeWidgetItem(ui->treeWidget);
    fillTreeWidget(ui->treeWidget , nullptr , s.answer());

}

