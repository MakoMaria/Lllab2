#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include "Stack.h"

class Calculator {
private:
    bool isOperator(char c);
    int performOperation(char operation, int operand1, int operand2);

public:
    int evaluate(const std::string& postfixExpression);
};

#endif
