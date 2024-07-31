#include "Builder.h"

int main() {
    PersonDirector* director;
    ConcretePersonBuilder builder;

    director->setBuilder(&builder);
    director->constructSimplePerson("Carl Jhonson", 32, "Grove Street");

    Person* person = builder.getResult();
    person->print();

    delete person();
    return 0;
}