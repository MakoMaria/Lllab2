#include <iostream>
#include <string>
#include "Calculator.h"

int main() {
    Calculator calculator;

    std::string expression;
    std::cout << "Enter a postfix expression: ";
    std::getline(std::cin, expression);

    int result = calculator.evaluate(expression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
