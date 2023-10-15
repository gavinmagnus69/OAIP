//
// Created by Roman on 23.12.2022.
//
#include "lab8 1.h"
void add(long long &n){
    std::cin.getline(hu[n+1].name, 50);
    printf("Name: ");
    std::cin.getline(hu[n+1].name, 50);
    printf("Surname: ");
    std::cin.getline(hu[n+1].surname, 50);
    printf("Midname: ");
    std::cin.getline(hu[n+1].midname, 50);
    printf("Adress: ");
    std::cin.getline(hu[n+1].adress, 50);
    printf("Discount: ");
    chk(&hu[n+1].dis);
    n++;
}