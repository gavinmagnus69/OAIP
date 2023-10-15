#include <iostream>
#include "BinaryOperation.h"

bool check_equals(Expression const *left, Expression const *right) {
    std::cout << left << ' ' << *(void **) left << ' ' << (void *) left << ' ' << (void **) left << '\n';
    std::cout << right << ' ' << *(void **) right << ' ' << (void *) right << ' ' << (void **) right << '\n';
    return *(void **) left == *(void **) right;

}
int main() {
    Expression *e = new BinaryOperation(new Number(13), '*', new Number(21));
    Expression *d = new BinaryOperation(new Number(9), '+', new Number(1));
    std::cout << e->evaluate() << '\n' << check_equals(e, d);
    return 0;
}