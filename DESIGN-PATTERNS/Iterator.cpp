#include "Iterator.h"

#include <iostream>

int main() {
    MyVector<std::string> vector;
    vector.add("PS");
    vector.add("Xbox");
    vector.add("Nintendo Switch");

    auto *ite = vector.createIterator();

    while (ite->hasNext()) {
        if(!ite->hasNext()) { std::cout << ite->next() << " ";
}
        std::cout << ite->next() << ", ";
    }

    delete ite;
    return 0;
}
