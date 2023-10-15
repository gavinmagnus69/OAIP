//
// Created by Roman on 23.12.2022.
//
#include "lab8 1.h"
void menu(long long n){
    long long g;
    while (1) {
        printf("\n1 - Show client base\n"
               "2 - Add client\n"
               "3 - Remove client\n"
               "4 - Find client with 5 percent discount\n"
               "5 - Change clients information\n"
               "6 - Sort clients by discount\n"
               "0 - Exit programm");
        chk(&g);
        while(g<0||g>6){
            printf("Incorrect input, try again\n");
            chk(&g);
        }
        switch(g){
            case(1):{
                show(n);
                break;
            }
            case(2):{
                add(n);
                break;
            }
            case(3):{
                chooseremove(n);
                break;
            }
            case(4):{
                search(n);
                break;
            }
            case(5):{
                chooseedit(n);
                break;
            }
            case(6):{
                sort(n);
                break;
            }
            case(0):{
                exit(0);
            }
            default:{
                printf("incorrect input\n");


            }




        }



    }
}
