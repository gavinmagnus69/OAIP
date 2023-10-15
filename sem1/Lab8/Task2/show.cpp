//
// Created by Roman on 23.12.2022.
//
#include "lab8 2.h"
void show(long long n ){

    for(int i =1;i<=n;i++){
        printf("\nDate: \n");
        printf("%s",(bu[i].date));
        printf("\nCost: \n");
        printf("%s$",(bu[i].money));
        printf("\nNum: \n");
        printf("%s",(bu[i].num));
        printf("\nTime: \n");
        printf("%sc",(bu[i].time));
        printf("\nTown: \n");
        printf("%s",(bu[i].town));
    }

}