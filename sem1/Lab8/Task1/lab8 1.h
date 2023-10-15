#include <iostream>
#include <cstdio>
#include <cstring>

#ifndef LAB8_LAB8_1_H
#define LAB8_LAB8_1_H
struct human {
    char name[51];
    char surname[51];
    char midname[51];
    char adress[51];
    long long dis;
};
extern human * hu;

void menu(long long n );
void add(long long &n);
void show(long long n);
void chooseedit(long long n);
void chooseremove(long long n );
void search(long long n );
void sort(long long n );
void chk(long long* a);
long long  chooseenter();


#endif //LAB8_LAB8_1_H
