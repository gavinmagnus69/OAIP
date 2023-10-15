//
// Created by Roman on 23.12.2022.
//
#include "lab8 1.h"
void search(long long n ){
    for (int i = 1 ; i<=n;i++){
        if(hu[i].dis!=5){
            continue;
        }
        printf("\nclients with 5 percent discount, num: \n");
        printf("%i",i);
        printf("\nName: ");
        printf("%s",(hu[i].name));
        printf("\nSurName: ");
        printf("%s",(hu[i].surname));
        printf("\nmidName: ");
        printf("%s",(hu[i].midname));
        printf("\nAdress: ");
        printf("%s",(hu[i].adress));
        printf("\nDiscount: ");
        std::cout<<hu[i].dis;
        printf("\n");
    }
}