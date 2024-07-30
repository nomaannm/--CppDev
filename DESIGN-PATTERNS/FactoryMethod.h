#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H
#include <iostream>
/*
 * We define an interface called factory to handle instantiation of different kinds of objects uniformly across all the divisions of the code.
 * Factory is responsible for encapsulating the business logic of creation of objects of a particular shared type.
 */

class IShape {
public:
       virtual void draw() const = 0;
       virtual ~IShape()= default;
};

class Circle final : public IShape {
public:
       void draw() const override {
           std::cout << "Drawing a circle!" << std::endl ;
       }
};

class Triangle final : public IShape {
public:
       void draw() const override {
              std::cout << "Drawing a triangle!" << std::endl;
       }
};


// FACTORIES
class IFactoryMethod {
public:
       [[nodiscard]] virtual IShape* createShape() const = 0;
       virtual ~IFactoryMethod()= default;
};

class CircleFactory final : public IFactoryMethod {
public:
       [[nodiscard]] IShape* createShape() const override {
              return new Circle();
       }
};

class TraingleFactory final : public IFactoryMethod {
public:
       [[nodiscard]] IShape* createShape() const override {
              return new Triangle();
       }
};

#endif //FACTORYMETHOD_H
