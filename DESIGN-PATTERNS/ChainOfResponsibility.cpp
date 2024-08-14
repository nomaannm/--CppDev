#include "ChainOfResponsibility.h"

int main() {
    ConcreteHandler1 handler1;
    ConcreteHandler2 handler2;

    handler1.setNext(&handler2);

    handler1.handleRequest("Request1");
    handler1.handleRequest("Request2");
    handler2.handleRequest("UnknownRequest");

    return 0;
}