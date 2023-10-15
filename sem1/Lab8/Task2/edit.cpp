//
// Created by Roman on 23.12.2022.
//
#include "lab8 2.h"
void chooseedit(long long n) {
   printf("Enter client num: \n");
    long long x;
    chk(&x);
    while (x < 1 || x >n) {
        printf("Incorrect input, try again\n");
       chk(&x);
    }
    printf("\nDate: ");
    std::cin.getline(bu[x].date, 50);
    printf("\nCost: ");
    std::cin.getline(bu[x].money, 50);
    printf("\nNum: ");
    std::cin.getline(bu[x].num, 50);
    printf("\nTime: ");
    std::cin.getline(bu[x].time, 50);
    printf("\nTown: ");
    std::cin.getline(bu[x].town, 50);
    for (int j = 0; j < 50; j++) {
        if ((!isdigit(bu[x].money[j]) && bu[x].money[j] != 0) || (!isdigit(bu[x].time[j]) &&bu[x].time[j] != 0)) {
            printf("\nOnly digits are allowed\n");
            del(n ,x);
            break;
        }
    }
}