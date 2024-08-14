#ifndef CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_H
#include <iostream>
#include <string>
/*
 * Chain of Responsibility is a behavioral design pattern that lets you pass requests along a chain of handlers.
 * Upon receiving a request, each handler decides either to process the request or to pass it to the next handler
 * in the chain.
 * This pattern transforms stand-alone behaviours into stand-alone objects called handlers.
 * The Chain of Responsibility pattern is a behavioral design pattern used to achieve loose coupling in software design.
 */

class Handler {
public:
       virtual ~Handler() = default;
       virtual void setNext(Handler* nextHandler) = 0;
       virtual void handleRequest(const std::string& request) = 0;
};

class ConcreteHandler1 final : public Handler {
public:
    void setNext(Handler *nextHandler) override {
        next = nextHandler;
    }

    void handleRequest(const std::string &request) override {
        if(request == "Request1") {
            std::cout << "Concrete handler 1 handling requests!" << std::endl;
        } else if(next != nullptr){
            next->handleRequest(request);
        } else {
            std::cout << "Cant pass it down\n";
        }
    }
private:
    Handler* next = nullptr;
};

class ConcreteHandler2 final : public Handler {
public:
    void setNext(Handler *nextHandler) override {
        next = nextHandler;
    }

    void handleRequest(const std::string &request) override {
        if(request == "Request2") {
            std::cout << "Concrete handler 2 handling requests!" << std::endl;
        } else if(next != nullptr) {
            next->handleRequest(request);
        } else {
            std::cout << "Can't pass it down!\n";
        }
    }
private:
    Handler* next = nullptr;
};






#endif //CHAINOFRESPONSIBILITY_H
