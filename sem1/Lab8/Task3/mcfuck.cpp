//
// Created by Roman on 23.12.2022.
//
#include "lab8 3.h"
void mc::show() {
    printf("\nid: ");
    std::cout<<id;
    printf("\ntown: ");
    std::cout<<town;
    printf("\ndate: ");
    std::cout<<date;
    printf("\nnum: ");
    std::cout<<num;
    printf("\ntime: ");
    std::cout<<time;
    printf("\ncost: ");
    std::cout<<cost;
}

int mc::edit(int n) {
  printf("\nenter client num: \n");
    int k = 0;
    chk(&k);
    while (k < 1 || k > n) {
        printf("\nIncorrecty input, try again\n");
        chk(&k);
    }
    printf("\nenter id: \n");
    std::cin >> id;
    printf("\ntown: \n");
    std::cin >> town;
    printf("\ndate: \n");
    std::cin >> date;
    printf("\nNum: \n");
    std::cin >> num;
    printf("\nTime: \n");
    std::cin >> time;
    printf("\nCost: \n");
    std::cin >> cost;
    return k;
}

void mc::in() {
    printf("\nenter id: \n");
    std::cin >> id;
    printf("\ntown: \n");
    std::cin >> town;
    printf("\ndate: \n");
    std::cin >> date;
    printf("\nNum: \n");
    std::cin >> num;
    printf("\nTime: \n");
    std::cin >> time;
    printf("\nCost: \n");
    std::cin >> cost;
}

int mc::del(int n) {
    printf("\nenter num of convers: \n");
    int k = 0;
    chk(&k);
    while (k < 1 || k > n) {
        printf("Incorrect input, try again\n");
        chk(&k);
    }
    return k;
    isd = 1;
}