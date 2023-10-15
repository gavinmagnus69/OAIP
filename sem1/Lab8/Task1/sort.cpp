//
// Created by Roman on 23.12.2022.
//
#include "lab8 1.h"
void sort(long long n ){
    for(int i = 2;i<=n;i++ ){
        int j = i-1;
        while(j>0 &&hu[j].dis>hu[j+1].dis ){
            std::swap(hu[j],hu[j+1]);
            j--;
        }
    }


}