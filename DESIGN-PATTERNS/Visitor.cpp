#include "Visitor.h"

void Hardwaredev::visit(const Console *playStation) const {
        std::cout << "Fixed the playstation!\n";
}

void Hardwaredev::visit(const Laptop *macBook) const {
    std::cout << "Fixed macbook!\n";
}

void Softwaredev::visit(const Console *playStation) const {
    std::cout << "Installed the latest software in the PS.\n";
}

void Softwaredev::visit(const Laptop *macBook) const {
    std::cout << "Installed the latest software in this MacBook.\n";
}

void Console::accept(Dev *visitor) const {
    visitor->visit(this);
}

void Laptop::accept(Dev *visitor) const {
    visitor->visit(this);
}


int main() {
    Console Playstation;
    Laptop Mac;

    Hardwaredev hardwaredev;
    Softwaredev softwaredev;

    Playstation.accept(&hardwaredev);
    Playstation.accept(&softwaredev);

    Mac.accept(&hardwaredev);
    Mac.accept(&softwaredev);
    return 0;
}


