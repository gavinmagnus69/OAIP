//
// Created by Roman on 23.12.2022.
//
#include "lab8 3.h"
void zad() {
    int n;
    FILE * fonk;
    fonk = fopen("C:/romanfiles/labs/lab8 3/iob/b.bin", "rb+");
    fseek(fonk, 0, SEEK_SET);
    fread(&n, sizeof(int), 1, fonk);
    mc ban;
    char tmp[50];
    std::cout << "Enter towns\n";
    std::cin >> tmp;
    int sum = 0;
    int time = 0;
    for (int i = 0; i < n; i++) {
        fread(&ban, sizeof(mc), 1, fonk);
        if (strcmp(ban.town, tmp) == 0) {
            time += ban.time;
            sum += ban.time * ban.cost;
        }
    }
    std::cout << "conversation  " << time << "sec costs " << sum << "$\n";
}