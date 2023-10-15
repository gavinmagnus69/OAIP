//
// Created by Roman on 23.12.2022.
//
#ifndef LAB8_3_MEINCLASS_H
#define LAB8_3_MEINCLASS_H
class mc {
    int id;
    char date[50];
    char num[50];
    union {
        bool isd = 0;
        bool tmp;
    };
public:
    int cost;
    int time;
    char town[50];
    void show();
    int edit(int n);
    int del(int n);
    void in();
};

#endif //LAB8_3_MEINCLASS_H
