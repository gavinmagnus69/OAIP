//
// Created by Roman on 07.03.2023.
//

#include "BinaryOperation.h"
double BinaryOperation::evaluate() {
    switch (sign) {
        case '+': {
            value = first->evaluate() + last->evaluate();
            break;
        }
        case '-': {
            value = first->evaluate() - last->evaluate();
            break;
        }
        case '*': {
            value = first->evaluate() * last->evaluate();
            break;
        }
        case '/': {
            value = first->evaluate() / last->evaluate();
            break;
        }
    }
    return value;
}

BinaryOperation::BinaryOperation(Number *a, char hz, Number *b) : first(a), sign(hz), last(b) {
}

BinaryOperation::~BinaryOperation() {
    delete first;
    delete last;
}