#ifndef OPZ_H
#define OPZ_H
#include "linkedlist.h"
#include "QString"
#include "linkedlist2.h"
//#define long ll
//#define double ld
class opz
{
public:
    opz();
    bool isOperator(QChar c);
    int getPriority(QChar c);
    QString toopz(QString s,linkedlist l);
   double calculator(QString s,linkedlist l1,linkedlist2 l2 , double a,double b, double c,double d,double e);
};

#endif // OPZ_H
