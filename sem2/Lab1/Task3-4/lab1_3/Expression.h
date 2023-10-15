//
// Created by Roman on 07.03.2023.
//

#ifndef LAB1_3_EXPRESSION_H
#define LAB1_3_EXPRESSION_H


class Expression {
protected:
    double value;
public:
    virtual ~Expression(){}

    virtual double evaluate() = 0;
};


#endif //LAB1_3_EXPRESSION_H
