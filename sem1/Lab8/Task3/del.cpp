//
// Created by Roman on 23.12.2022.
//
#include "lab8 3.h"
void del() {
    int n;
    FILE * fonk;
    fonk = fopen("C:/romanfiles/labs/lab8 3/iob/b.bin", "rb+");
    fseek(fonk, 0, SEEK_SET);
    fread(&n, sizeof(int), 1, fonk);
    mc ban;
    int k = ban.del(n);
    k--;
    for (k; k < n; k++) {
        fseek(fonk, sizeof(int) + (k + 1) * sizeof(mc), SEEK_SET);
        fread(&ban, sizeof(mc), 1, fonk);
        fseek(fonk, sizeof(int) + k * sizeof(mc), SEEK_SET);
        fwrite(&ban, sizeof(mc), 1, fonk);
    }
    fseek(fonk, 0, SEEK_SET);
    --n;
    fwrite(&(n), sizeof(int), 1, fonk);
    fclose(fonk);
}