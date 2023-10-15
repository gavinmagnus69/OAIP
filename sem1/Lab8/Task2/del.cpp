//
// Created by Roman on 23.12.2022.
//
#include "lab8 2.h"
void del(long long &n ,long long k){
    for (long long i = k + 1; i <= n; i++) {
        strcpy(bu[i - 1].money, bu[i].money);
        strcpy(bu[i - 1].date, bu[i].date);
        strcpy(bu[i - 1].num, bu[i].num);
        strcpy(bu[i - 1].town, bu[i].town);
        strcpy(bu[i - 1].time, bu[i].time);
    }
   n--;
}
void chooseremove(long long n ) {
    printf("\nEnter num of client\n");
    long long k = 0;
    chk(&k);
    while (k < 1 || k > n) {
        printf("Incorrect input, try again\n");
        chk(&k);
    }
    del(n,k);
}
