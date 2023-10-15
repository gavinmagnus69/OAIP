//
// Created by Roman on 07.03.2023.
//

#include "Number.h"
double Number::setValue(double a) {
    value = a;
    return a;
}

double Number::evaluate() {
    return value;
}

Number::Number(double a) { value = a; }