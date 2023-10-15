//
// Created by Roman on 23.12.2022.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#ifndef LAB8_2_LAB8_2_H
#define LAB8_2_LAB8_2_H
struct atass{
    char date[50];
    char town[50];
    char time[50];
    char money[50];
    char num[50];
};
extern atass * bu;

void menu(long long n);
long long chooseenter();
void show(long long n );
void add(long long &x);
void chooseremove(long long n);
void chooseedit(long long n);
void output(long long n);
void del(long long &n,long long k);
void chk(long long * x);
#endif //LAB8_2_LAB8_2_H
