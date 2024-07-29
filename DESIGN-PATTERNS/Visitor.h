#ifndef VISITOR_H
#define VISITOR_H
#pragma once
#include <iostream>

/*
 * The Visitor design pattern is a behavioral pattern used to separate an algorithm from the object structure on which it operates.
 * This pattern allows you to add new operations to a collection of objects without modifying their classes.
 */

class Dev;

//Visitable
class Product {
public:
    virtual void accept(Dev* visitor) const = 0;
};

class Console : public Product {
public:
    void accept(Dev *visitor) const override;
};

class Laptop : public Product {
public:
    void accept(Dev *visitor) const override;
};

//Visitor
class Dev {
public:
       virtual ~Dev() = default;
       virtual void visit(const Console* playStation) const = 0;
       virtual void visit(const Laptop* macBook) const = 0;
};

class Hardwaredev : public Dev {
public:
       void visit(const Console* playStation) const override;
       void visit(const Laptop* macBook) const override;
};

class Softwaredev : public Dev {
public:
        void visit(const Console* playStattion) const override;
        void visit(const Laptop* macBook) const override;
};




#endif //VISITOR_H
