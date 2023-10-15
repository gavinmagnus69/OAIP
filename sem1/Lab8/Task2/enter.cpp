//
// Created by Roman on 23.12.2022.
//
#include "lab8 2.h"
long long chooseenter() {
    std::ifstream inp("C:/romanfiles/labs/lab8 2/io/i.in");
    int i = 1;
    while (inp.getline(bu[i].date, 50)) {
        inp.getline(bu[i].money, 50);
        inp.getline(bu[i].num, 50);
        inp.getline(bu[i].time, 50);
        inp.getline(bu[i++].town, 50);
        for (int j = 0; j < 50; j++) {
            if ((!isdigit(bu[i - 1].money[j]) && bu[i - 1].money[j] != 0) || (!isdigit(bu[i - 1].time[j]) &&bu[i - 1].time[j] != 0)) {
                printf("\nonly digits are allowed\n");
                i--;
                break;
            }
        }
    }
   return i-1;
}