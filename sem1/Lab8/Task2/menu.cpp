//
// Created by Roman on 23.12.2022.
//
#include "lab8 2.h"
void menu(long long n) {

    long long k = 0;
    while (true) {

        printf("1 - Show clients\n"
               "2 - Add client\n"
               "3 - Remove client\n"
               "4 - Edit client\n"
               "0 - Exit\n");

      chk(&k);
        while (k < 0 || k > 4) {
            printf("Incorrect input");
            chk(&k);
        }
        switch (k) {
            case (1): {
                show( n);
                break;
            }
            case (2): {
                add(n);
                break;
            }
            case (3): {
                chooseremove(n);
                break;
            }
            case (4): {
                chooseedit(n);
                break;
            }
            case (0): {
                output(n);
                exit(0);
            }
            default: {
                printf("Incorrect input\n");
            }
        }
    }
}