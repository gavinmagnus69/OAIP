//
// Created by Roman on 23.12.2022.
//
#include "lab8 3.h"
void edit() {
    int n;
    FILE *fonk;
    fonk = fopen("C:/romanfiles/labs/lab8 3/iob/b.bin", "rb+");
    fseek(fonk, 0, SEEK_SET);
    fread(&n, sizeof(int), 1, fonk);
    mc ban;
    int k = ban.edit(n);
    fseek(fonk, (k - 1) * sizeof(mc) + sizeof(int), SEEK_SET);
    fwrite(&ban, sizeof(mc), 1, fonk);
    fclose(fonk);
}