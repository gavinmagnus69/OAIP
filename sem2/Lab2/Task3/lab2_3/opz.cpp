#include "opz.h"
using namespace std;
#include <QDebug>
opz::opz()
{

}
bool opz::isOperator(QChar c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int opz::getPriority(QChar c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return 0;
    }
}
QString opz::toopz(QString s,linkedlist l){
    QString ans;
    for(int i =0;i<s.length();i++ ){
        //std::cout<<s[i]<<endl;
        if(!isOperator(s[i])&&s[i]!='('&&s[i]!=')'){
            //cout<<"case 1\n";
            ans+=s[i];
            ans+=" ";
        }
        else if(isOperator(s[i])){
            while(l.head!= nullptr&&(getPriority(s[i])<= getPriority(l.head->t))){
                ans+=l.head->t;
                ans+=" ";
                //cout<<"case 2\n";
                l.pop_front();
            }
            //cout<<s[i]<<" to stack\n";
            l.pushfront(s[i]);
        }
        else if(s[i]=='('){
            l.pushfront(s[i]);

        }
        else if(s[i]==')'){
            while(l.head->t!='('){
                //cout<<"case 3\n";
                ans+=l.head->t;
                ans+=" ";
                l.pop_front();
            }
            l.pop_front();


        }



    }
    while(l.head!= nullptr){
        ans += l.head->t;
        ans+=" ";
        l.pop_front();
    }
    //std::cout<<ans;
    return ans;
}
double opz::calculator(QString s,linkedlist l11,linkedlist2 l22,  double a,double b, double c,double d, double e){
    linkedlist l1;
    linkedlist2 l2;
    int cnt=0;
    for(int i =0;i<s.length();i++){
        if(s[i]!=' '){
            cnt++;
        }

    }
    QString * bebra = new QString[cnt];
    int j=0;
    for(int i =0;i<s.length();i++){
        qDebug()<<s[i];
        if(s[i]!=' '){
            if(s[i]=='a'){
                qDebug()<<"c1";
                bebra[j]=QString::number(a);
                qDebug()<<bebra[j];
                j++;
                continue;

            }
            if(s[i]=='b'){
                qDebug()<<"c2";
                bebra[j]=QString::number(b);
                qDebug()<<bebra[j];
                j++;
                continue;

            }
            if(s[i]=='c'){
                qDebug()<<"c3";
                bebra[j]=QString::number(c);
                qDebug()<<bebra[j];
                j++;
                continue;

            }
            if(s[i]=='d'){
                qDebug()<<"c4";
                bebra[j]=QString::number(d);
                qDebug()<<bebra[j];
                j++;
                continue;

            }
            if(s[i]=='e'){
                qDebug()<<"c5";
                bebra[j]=QString::number(e);
                qDebug()<<bebra[j];
                j++;
                continue;

            }
            else{
                bebra[j]=s[i];
                j++;

            }

        }
    }
    for(int i =0;i<cnt;i++){
        qDebug()<<bebra[i];
    }
    for(int i =0;i<cnt;i++){
        qDebug()<<bebra[i];
        if(bebra[i]!='+'&&bebra[i]!='-'&&bebra[i]!='*'&&bebra[i]!='/'){
            qDebug()<<"push"<<bebra[i];
            l2.pushfront(bebra[i].toDouble());
        }
        else{
            double temp;
            if(bebra[i]=='+'){
                qDebug()<<l2.head->next->t<<"+"<<l2.head->t;
            temp = l2.head->next->t+l2.head->t;
            }
            if(bebra[i]=='-'){
                qDebug()<<l2.head->next->t<<"-"<<l2.head->t;
            temp = (l2.head->next->t)-(l2.head->t);
            }
            if(bebra[i]=='*'){
                qDebug()<<l2.head->next->t<<"*"<<l2.head->t;
            temp = l2.head->next->t*l2.head->t;
            }
            if(bebra[i]=='/'){
                qDebug()<<l2.head->next->t<<"/"<<l2.head->t;
            temp = l2.head->next->t/l2.head->t;
            }
            l2.pop_front();
            l2.pop_front();
            qDebug()<<"temp = "<<temp;
            l2.pushfront(temp);
        }
    }
    return l2.head->t;









}
