#include "Prototype.h"

#include "Visitor.h"

int main() {
    //Create a prototype registery
    ProtoypesRegister registery;

    registery.addPrototype("Type1", std::make_unique<ConcretePrototype1<float>>(3.42));
    registery.addPrototype("Type2", std::make_unique<ConcretePrototype2>("132"));

    auto prototype1 = registery.create("Type1");
    auto prototype2 = registery.create("Type2");

    prototype1->show();
    prototype2->show();

    return 0;
}
