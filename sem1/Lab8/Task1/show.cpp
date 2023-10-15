//
// Created by Roman on 23.12.2022.
//
#include "lab8 1.h"
void show(long long n) {
    for (int i = 1; i <= n; i++) {
        std::cout << "\nClient number: " << i << "\n";
        printf("Name: ");
        std::cout << hu[i].name;
        printf("\nSurname: ");
        std::cout << hu[i].surname;
        printf("\nMidname: ");
        std::cout << hu[i].midname;
        printf("\nAdress: ");
        std::cout << hu[i].adress;
        printf("\nDiscount: ");
        std::cout << hu[i].dis;
        std::cout<<"\n//////////////////////////";
    }
}