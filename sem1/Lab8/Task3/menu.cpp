//
// Created by Roman on 23.12.2022.
//
#include "lab8 3.h"
void menu() {

    int n = 0;
    while (1) {

        printf(
               "1 - show base\n"
               "2 - new conv\n"
               "3 - edit conv\n"
               "4 - removing conv\n"
               "5 - time of conv and cost of conv\n"
               "6 - sort conv\n"
               "0 - exit\n");

        chk(&n);
        while (n < 0 || n > 6) {
            printf("Incorrect input , try again\n");
            chk(&n);
        }
        switch (n) {
            case 1: {
                show();
                break;
            }
            case 2:{
                w();
                break;
            }
            case 3:{
                edit();
                break;
            }
            case 4:{
                del();
                break;
            }
            case 5:{
                zad();
                break;
            }
            case 6:{
                sort();
                break;
            }
            case 0: {
                return;
            }
            default: {
                printf("incorrect input\n");
                break;
            }
        }
    }
}