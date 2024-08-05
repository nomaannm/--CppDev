#include "Flyweight.h"

int main() {
    FlyweightFactory factory;

    SharedFlyweight flyweight1 = factory.getFlyweight("sharedflyweight1");
    SharedFlyweight flyweight2 = factory.getFlyweight("sharedflyweight2");

    flyweight1->operation("clientstate1");
    flyweight2->operation("clientstate2");

    return 0;
}
