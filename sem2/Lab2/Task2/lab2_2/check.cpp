#include "check.h"
#include <QDebug>

check::check()
{


}
int check::chk(QString s){
    int * c = new int[s.length()];
    for(int i =0;i<s.length();i++){
        c[i]=10;
    }
    for(int i =0;i<s.length();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            c[i]=2;
        }
        if(s[i]==')'||s[i]=='}'||s[i]==']'){
                    c[i]=-2;
                }
    }


    index1 =0;
    index2=s.length()-1;
    qDebug()<<s.length();
    while(index1!=s.length()-1){
        if(c[index1]==-2){
            return index1;
        }
        if(s[index1]=='('||s[index1]=='{'||s[index1]=='['){
            qDebug()<<"case1: "<<index1;
            QChar t = s[index1];
            QChar r;
            if(t=='('){
                QChar r = ')';
            }
            if(t=='{'){
                QChar r = '}';
            }
            if(t=='['){
                QChar r = ']';
            }
            c[index1]=1;
            int tempindex1 =index1;
            bool minichk =0;
            while(tempindex1!=index2){
                if(s[tempindex1]==r){
                    qDebug()<<"case 2";
                    index2 = tempindex1;

                    c[index2] = 1;
                    minichk =1;
                    break;
                }
             tempindex1++;
            }
            if(minichk==0){
                return index1;
            }


        }




        index1++;
    }
    qDebug()<<"success";
    return -1;



}
