#include "prodlist.h"

Prodlist::Prodlist()
{
    cap = 100;

    size = 0;
}
void Prodlist::selectcap(int a){
    this->cap = a;
}
void Prodlist::push_back(Production temp){
    prod[size] = temp;
    size++;
}
void Prodlist::erase(int index){
    Production * temp = new Production[cap];
    int j =0;
    for(int i = index+1;i<size;i++){
        temp[j]=prod[i];
        j++;
    }
    j=0;
    for(int i =index;i<size-1;i++){
        prod[i]=temp[j];
        j++;
    }
    size--;
    delete[] temp;
}
