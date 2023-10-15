//
// Created by Roman on 23.12.2022.
//
#include "lab8 2.h"
void add(long long &n ) {
    std::cin.getline(bu[n + 1].date, 50);
    printf("Date: ");
    std::cin.getline(bu[n + 1].date, 50);
    printf("Cost: ");
   std:: cin.getline(bu[n + 1].money, 50);
    printf("Num: ");
    std::cin.getline(bu[n + 1].num, 50);
    printf("Time: ");
    std::cin.getline(bu[n + 1].time, 50);
    printf("Town: ");
    std::cin.getline(bu[n + 1].town, 50);
    n++;
    for(int j = 0; j < 50; j++) {
        if ((!isdigit(bu[n + 1].money[j]) && bu[n + 1].money[j] != 0) || (!isdigit(bu[n + 1].time[j]) &&bu[n + 1].time[j] != 0)) {
            printf("\nOnlu digits are allowed\n");
            n--;
            break;
        }
    }
}