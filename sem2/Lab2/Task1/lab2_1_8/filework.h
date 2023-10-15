#ifndef FILEWORK_H
#define FILEWORK_H
#include <QFile>
#include "prodlist.h"
#include <QMessageBox>
class FileWork
{
public:
    FileWork();
    bool fromfile(QFile &file,Prodlist &a);
    void tofile(QFile &file, Prodlist a);
};

#endif // FILEWORK_H
