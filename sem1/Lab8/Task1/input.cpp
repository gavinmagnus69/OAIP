//
// Created by Roman on 23.12.2022.
//
#include "lab8 1.h"
long long enter1() {
    printf("Enter amount of clients: ");
    long long n;
    chk(&n);
    while (n < 1) {
        std::cout << "Incorrect input, try again\n";
        chk(&n);
    }
    for (int i = 1; i <= n; i++) {
        std::cin.getline(hu[i].name, 50);
        printf("Name: ");
        std::cin.getline(hu[i].name, 50);
        printf("Surname: ");
        std::cin.getline(hu[i].surname, 50);
        printf("Midname: ");
        std::cin.getline(hu[i].midname, 50);
        printf("Adress: ");
        std::cin.getline(hu[i].adress, 50);
        printf("Discount: ");
        chk(&hu[i].dis);
    }
    return n;
}
long long enter2() {
    long long i = 1;
    while (1) {
        std::cin.getline(hu[i].name, 50);
        printf("Name: ");
        std::cin.getline(hu[i].name, 50);
        printf("Surname: ");
        std::cin.getline(hu[i].surname, 50);
        printf("Midname: ");
        std::cin.getline(hu[i].midname, 50);
        printf("Adress: ");
        std::cin.getline(hu[i].adress, 50);
        printf("Discount: ");
        chk(&hu[i].dis);
        if (hu[i].dis == 0) {
            break;
        }
        i++;
    }
    return i;
}
long long enter3() {
    int i = 1;
    char a;
    while (1) {
        std::cin.getline(hu[i].name, 50);
        printf("Name: ");
        std::cin.getline(hu[i].name, 50);
        printf("Surname: ");
        std::cin.getline(hu[i].surname, 50);
        printf("Midname: ");
        std::cin.getline(hu[i].midname, 50);
        printf("Adress: ");
        std::cin.getline(hu[i].adress, 50);
        printf("Discount: ");
        chk(&hu[i].dis);
        printf("Do you want to continue? Y/N");
        a = getchar();
        if (tolower(a) == 'y') {
            break;
        }
        i++;

    }
    return i;

}
long long  chooseenter() {
    printf("what kind of entering do you prefer\n"
           "1 - with known amount of clients\n"
           "2 - until discount will be equal to 0\n"
           "3 - step by step\n");
    long long n;
    long long ans=0;
    chk(&n);
    while (n < 1 || n>3) {
        printf("Incorrect input, try again\n");
        chk(&n);
    }
    if (n == 1) {
        ans=enter1();
    }
    if (n == 2) {
        enter2();
    }
    if (n == 3) {
        enter3();
    }
    return ans;
}