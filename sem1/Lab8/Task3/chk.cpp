//
// Created by Roman on 23.12.2022.
//
#include "lab8 3.h"
void chk(int * a) {
    while (true) {
        std::cin >> *a;
        if (std::cin.fail() || (std::cin.peek() != '\n' && std::cin.peek() != ' ')) {
            std::cin.clear();
            std::cin.ignore(111111, '\n');
            std::cerr << "Incorrect input,try again\n";
        }
        else{
            return;
        }
    }
}