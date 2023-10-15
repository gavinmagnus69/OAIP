//
// Created by Roman on 23.12.2022.
//
#include "lab8 2.h"
std::vector <std::string> a;
std::vector<long long> b;

void addjust(long long n ,char f[50], long long p) {
    bool cmp = 1;
    bool found = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] != f[j]) {
                cmp = false;
            }
        }
        if (cmp) {
            b[i] += p;
            found = true;
            break;
        }
        cmp = true;
    }
    if (!found) {
        a.emplace_back("");
        for (int i = 0; i < 50; i++) {
            if (f[i])
                a[a.size() - 1] += f[i];
        }
        b.push_back(p);
    }
}

void form(long long n ) {
    for (int i = 1; i <= n; i++) {
        addjust(n,bu[i].town, atoll(bu[i].money) * atoll(bu[i].time));
    }
}

void output(long long n) {
    std::ofstream out("C:/romanfiles/labs/lab8 2/io/o.out");
    form(n);
    for (int i = 0; i < a.size(); i++) {
        out << a[i] << " - " << b[i] << "$\n";
    }
}