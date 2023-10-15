//
// Created by Roman on 23.12.2022.
//
#include "lab8 3.h"
void sort() {
    int n;
    FILE *fonk;
    fonk = fopen("C:/romanfiles/labs/lab8 3/iob/b.bin", "rb+");
    fseek(fonk, 0, SEEK_SET);
    fread(&n, sizeof(int), 1, fonk);
    mc ban1;
    mc ban2;
    for (int i = 0; i < n - 1; i++) {
        fseek(fonk, sizeof(int) + (i + 1) * sizeof(mc), SEEK_SET);
        fread(&ban2, sizeof(mc), 1, fonk);
        fseek(fonk, sizeof(int) + i * sizeof(mc), SEEK_SET);
        fread(&ban1, sizeof(mc), 1, fonk);
        if (ban2.cost < ban1.cost) {
            fseek(fonk, sizeof(int) + (i + 1) * sizeof(mc), SEEK_SET);
            fwrite(&ban1, sizeof(mc), 1, fonk);
            fseek(fonk, sizeof(int) + i * sizeof(mc), SEEK_SET);
            fwrite(&ban2, sizeof(mc), 1, fonk);
            i -= 2;
        }
    }
    for (int i = 0; i < n / 2; i++) {
        fseek(fonk, sizeof(int) + (n - i - 1) * sizeof(mc), SEEK_SET);
        fread(&ban2, sizeof(mc), 1, fonk);
        fseek(fonk, sizeof(int) + i * sizeof(mc), SEEK_SET);
        fread(&ban1, sizeof(mc), 1, fonk);
        fseek(fonk, sizeof(int) + (n - i - 1) * sizeof(mc), SEEK_SET);
        fwrite(&ban1, sizeof(mc), 1, fonk);
        fseek(fonk, sizeof(int) + i * sizeof(mc), SEEK_SET);
        fwrite(&ban2, sizeof(mc), 1, fonk);
    }
    fseek(fonk, 0, SEEK_SET);
    fclose(fonk);
}