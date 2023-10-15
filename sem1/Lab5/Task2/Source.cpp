#include <iostream>
#include <Windows.h>


int main() {
    HINSTANCE load;
    load = LoadLibrary(L"dll.dll");
    typedef long double (*a)(void);
    a chk;
    chk = (a)GetProcAddress(load, "chk");
    typedef void (*b)(long long*);
    b chklong;
    chklong = (b)GetProcAddress(load, "chklong");
    typedef bool (*c)(long double);
    c ifsin;
    ifsin = (c)GetProcAddress(load, "ifsin");
    typedef bool (*d)(long double*, long long, long long);
    d recursion;
    recursion = (d)GetProcAddress(load, "recursion");
    typedef bool (*e)(void);
    e exetask;
    exetask=(e)GetProcAddress(load, "exetask");
    bool bl = exetask();
    if (bl) {
        std::cout << "true";
        return 0;
    }
    std::cout <<"bruh";
}