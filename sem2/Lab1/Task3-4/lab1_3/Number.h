//
// Created by Roman on 07.03.2023.
//

#ifndef LAB1_3_NUMBER_H
#define LAB1_3_NUMBER_H
#include "Expression.h"

class Number : public Expression {
public:
    ~Number() override= default;
    Number(double a);
    double evaluate() override;
    double setValue(double);
};


#endif //LAB1_3_NUMBER_H
