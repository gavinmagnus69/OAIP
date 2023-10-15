#ifndef PRODLIST_H
#define PRODLIST_H
#include "production.h"

class Prodlist
{
    int cap;
    int size;
public:
    Production * prod = new Production[50000];
    int showsize(){
       return this->size;
    }
    Prodlist();
    void selectcap(int a);
    void push_back(Production temp);
    void insert(int index,Production temp);
    void erase(int index);
};

#endif // PRODLIST_H
