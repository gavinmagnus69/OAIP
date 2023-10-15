#ifndef PRODUCTION_H
#define PRODUCTION_H
#include <QString>

class Production
{
public:
    QString name;
    QString amount;
    QString department;
    Production(){};
    Production(QString a, QString b, QString c);
};

#endif // PRODUCTION_H
