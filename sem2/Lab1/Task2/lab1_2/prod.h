#ifndef PROD_H
#define PROD_H
#include <QString>
#include <iostream>

class prod
{
public:
    QString prodtype;
    QString modelname;
    long long prodecode;
    long long price;
    long long amount;
    prod();
    prod(QString a,QString b , long long c , long long d, long long e): prodtype(a), modelname(b),prodecode(c),price(d),amount(e){}


};

#endif // PROD_H
