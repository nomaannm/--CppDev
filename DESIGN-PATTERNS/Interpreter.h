#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdexcept>
#include <string>
#include <unordered_map>

/*
 * The Interpreter pattern is a behavioral design pattern used to define a grammar for a language and provides an interpreter
 * to evaluate sentences in that language. It is useful in scenarios where you need to interpret or parse expressions within
 * a language or when you want to implement a simple scripting language.
 * Key Components of the Interpreter Pattern:
            AbstractExpression: Declares an interface for interpreting the context. All the concrete expressions
            derive from this interface or abstract class.

            TerminalExpression: Implements the interpretation method for terminals in the grammar, which are the basic
            symbols in the language.

            NonterminalExpression: Represents more complex rules of the grammar that are composed of terminal expressions
            or other non-terminal expressions.

            Context: Contains information that is global to the interpreter, such as input strings, variable mappings,
            or data needed by the interpreter to perform its tasks.

            Client: Constructs the abstract syntax tree (AST) from the grammar and initiates the interpretation process.
 */

// Abstract Expression
class Expression {
public:
    virtual int interpret(const std::unordered_map<std::string, int>& context) = 0;
    virtual ~Expression() = default;
};

//Terminal Expression for numbers
class NumberExpression final : public Expression {
private:
    int number;
public:
    explicit NumberExpression(const int num) : number{num} {}
    int interpret(const std::unordered_map<std::string, int> &context) override {
        return number;
    }
};

//Terminal Expression for variables
class VariablesExpression final : public Expression {
private:
    std::string name;
public:
    explicit VariablesExpression(const std::string& name) : name(name) {}
    int interpret(const std::unordered_map<std::string, int> &context) override {
        if(context.find(name) != context.end()) {
            return context.at(name);
        }
        throw std::runtime_error("Variable not found in context");

    }
};

//Non-terminal expression for addition
class AddExpression final : public Expression {
private:
    Expression* left;
    Expression* right;
public:
    AddExpression(Expression* left, Expression* right) : left{left}, right{right} {}
    int interpret(const std::unordered_map<std::string, int> &context) override {
        return left->interpret(context) + right->interpret(context);
    }
    ~AddExpression() override {
        delete left;
        delete right;
    }
};

// NonterminalExpression for subtraction
class SubtractExpression : public Expression {
private:
    Expression* left;
    Expression* right;
public:
    SubtractExpression(Expression* left, Expression* right) : left(left), right(right) {}
    int interpret(const std::unordered_map<std::string, int>& context) override {
        return left->interpret(context) - right->interpret(context);
    }
    ~SubtractExpression() override {
        delete left;
        delete right;
    }
};

// NonterminalExpression for multiplication
class MultiplyExpression final : public Expression {
private:
    Expression* left;
    Expression* right;
public:
    MultiplyExpression(Expression* left, Expression* right) : left(left), right(right) {}
    int interpret(const std::unordered_map<std::string, int>& context) override {
        return left->interpret(context) * right->interpret(context);
    }
    ~MultiplyExpression() override {
        delete left;
        delete right;
    }
};

// NonterminalExpression for division
class DivideExpression final : public Expression {
private:
    Expression* left;
    Expression* right;
public:
    DivideExpression(Expression* left, Expression* right) : left(left), right(right) {}
    int interpret(const std::unordered_map<std::string, int>& context) override {
        int rightVal = right->interpret(context);
        if (rightVal == 0) throw std::runtime_error("Division by zero");
        return left->interpret(context) / rightVal;
    }
    ~DivideExpression() override {
        delete left;
        delete right;
    }
};

//Utility function to parse integers from a string
int parseNumber(const std::string& str, size_t& pos) {
    std::string num;
    while(pos < str.size() && std::isdigit(str[pos])) {
        num += str[pos++];
    }

    return std::stoi(num);
}

// Utility function to parse a variable name from a string
std::string parseVariable(const std::string& str, size_t &pos) {
    std::string var;
    while (pos < str.size() && std::isalnum(str[pos])) {
        var += str[pos++];
    }
    return var;
}

// Parser and client to build the abstract syntax tree
Expression* parseExpression(const std::string& str , size_t &pos);

//Parses primary expressions like numbers, variables, or expressions in parantheses
Expression* parsePrimary(const std::string& str, size_t& pos ) {
    while(pos < str.size() && std::isspace(str[pos])) pos++;

    if(std::isdigit(str[pos])) {
        return new NumberExpression(parseNumber(str, pos));
    } else if(std::isalpha(str[pos])) {
        return new VariablesExpression(parseVariable(str, pos));
    } else if (str[pos] == '(') {
        pos++;  // Skip '('
        Expression* expr = parseExpression(str, pos);
        if (str[pos] == ')') {
            pos++;  // Skip ')'
        } else {
            throw std::runtime_error("Mismatched parentheses");
        }
        return expr;
    }

    throw std::runtime_error("Unexpected token");
}

// Parses multiplication and division
Expression* parseTerm(const std::string &str, size_t &pos) {
    Expression* left = parsePrimary(str, pos);
    while (pos < str.size()) {
        if (str[pos] == '*') {
            pos++;
            left = new MultiplyExpression(left, parsePrimary(str, pos));
        } else if (str[pos] == '/') {
            pos++;
            left = new DivideExpression(left, parsePrimary(str, pos));
        } else {
            break;
        }
    }
    return left;
}

// Parses addition and subtraction
Expression* parseExpression(const std::string &str, size_t &pos) {
    Expression* left = parseTerm(str, pos);
    while (pos < str.size()) {
        if (str[pos] == '+') {
            pos++;
            left = new AddExpression(left, parseTerm(str, pos));
        } else if (str[pos] == '-') {
            pos++;
            left = new SubtractExpression(left, parseTerm(str, pos));
        } else {
            break;
        }
    }
    return left;
}






#endif //INTERPRETER_H
