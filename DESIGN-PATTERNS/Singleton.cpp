#include "Singleton.h"

Singleton Singleton::_singleton;

void isSingleInstanceRunning(Singleton& singleton) {
    assert(&singleton == &Singleton::getSingletonInstance() && "The passed is not the only instance");
}

int main() {
    auto& singleton = Singleton::getSingletonInstance();
    singleton.Test();
    isSingleInstanceRunning(singleton);
    return 0;
}
