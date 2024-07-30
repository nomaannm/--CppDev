#include "FactoryMethod.h"

int main() {
    FactoryMethod* circleFactory = new CircleFactory();
    Shape* circle = circleFactory->createShape();
    circle->draw();
    delete circle;
    delete circleFactory;


    FactoryMethod* triangleFactory = new TraingleFactory();
    Shape* triangle = triangleFactory->createShape();
    triangle->draw();
    delete triangle;
    delete triangleFactory;

    return 0;
}
