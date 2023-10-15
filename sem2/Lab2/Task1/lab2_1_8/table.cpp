#include "table.h"

void table::updatetable(Prodlist &list){
   mui->tableWidget->setColumnCount(3);
   qDebug()<<list.showsize();
   mui->tableWidget->setRowCount(list.showsize());
   for(int i =0;i<list.showsize();i++){
       QTableWidgetItem * itm = new QTableWidgetItem(list.prod[i].name);
       mui->tableWidget->setItem(i,0,itm);
       QTableWidgetItem * itm2 = new QTableWidgetItem(list.prod[i].amount);
       mui->tableWidget->setItem(i,1,itm2);
       QTableWidgetItem * itm3 = new QTableWidgetItem(list.prod[i].department);
       mui->tableWidget->setItem(i,2,itm3);
   }
}
void table::cancel(Prodlist &list){
    int n1 = mui->tableWidget->rowCount();
    for(int i = 0;i<n1;i++){
        mui->tableWidget->showRow(i);
    }
    this->updatetable(list);
}
void table::deleteproduction(Prodlist &list, QString s){
    if(s==""){
        return;
    }
    for(int i =0;i<list.showsize();i++){
        QString temp = list.prod[i].name;
        if(s==temp){
            list.erase(i);
        }
    }
    for(int i =0;i<list.showsize();i++){
        QString temp = list.prod[i].name;
        if(s==temp){
            list.erase(i);
        }
    }
    for(int i =0;i<list.showsize();i++){
        QString temp = list.prod[i].name;
        if(s==temp){
            list.erase(i);
        }
    }
    this->updatetable(list);
}
void table::find(Prodlist &list,QString s){
    for(int i =0;i<list.showsize();i++){
        if(s!=list.prod[i].department){
            mui->tableWidget->hideRow(i);
        }
    }
}
void table::findbyamount(Prodlist &list,QString s){
    int n = s.toInt();
    for(int i =0;i<list.showsize();i++){
        if(n>=list.prod[i].amount.toInt()){
            mui->tableWidget->hideRow(i);
        }

    }
}
void table::findbyname(Prodlist &list,QString s){
    for(int i =0;i<list.showsize();i++){
        if(s!=list.prod[i].name){
            mui->tableWidget->hideRow(i);
        }
    }


}







