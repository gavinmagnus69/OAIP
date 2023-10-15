//
// Created by Roman on 23.12.2022.
//
#include "lab8 3.h"
void w() {
    int n;
    FILE *fonk;
    fonk = fopen("C:/romanfiles/labs/lab8 3/iob/b.bin", "rb+");
    fseek(fonk, 0, SEEK_SET);
    mc ban;
    ban.in();
    fread(&n, sizeof(int), 1, fonk);
    fseek(fonk, (n) * sizeof(mc)+ sizeof(int), SEEK_SET);
    fwrite(&ban, sizeof(mc), 1, fonk);
    fseek(fonk, 0, SEEK_SET);
    fwrite(&(++n), sizeof(int), 1, fonk);
    fclose(fonk);
}
