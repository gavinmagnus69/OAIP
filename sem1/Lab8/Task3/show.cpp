//
// Created by Roman on 23.12.2022.
//
#include "lab8 3.h"
void show() {
    int n;
    FILE *fonk;
    fonk = fopen("C:/romanfiles/labs/lab8 3/iob/b.bin", "rb+");
    fseek(fonk, 0, SEEK_SET);
    fread(&n, sizeof(int), 1, fonk);
    mc ban;
    for (int i = 0; i < n; i++) {
        fread(&ban, sizeof(mc), 1, fonk);
        ban.show();
    }
    fclose(fonk);
}