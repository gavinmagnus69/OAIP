//
// Created by Roman on 07.03.2023.
//

#ifndef LAB1_3_BINARYOPERATION_H
#define LAB1_3_BINARYOPERATION_H
#include "Expression.h"
#include "Number.h"
class BinaryOperation : public Expression {
    Number *first, *last;
    char sign;
public:
    double evaluate() override;

    BinaryOperation(Number *, char, Number *);

    ~BinaryOperation() override;
};

#endif //LAB1_3_BINARYOPERATION_H
