#include "Interpreter.h"

#include <iostream>
#define FIVE 5
#define SIX 6

int main() {
    // Context with variables
    std::unordered_map<std::string, int> context = {{"x",FIVE}, {"y",SIX}};

    //Expression to evaluate
    std::string exprStr = "(x + y) + (x * y)";
    size_t pos = 0;

    try {
        // Parse the expression
        Expression* expression = parseExpression(exprStr, pos);

        const int result = expression->interpret(context);
        std::cout << "Result : " << result << std::endl;

        delete expression;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;

}