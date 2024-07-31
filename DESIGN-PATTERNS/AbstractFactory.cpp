#include "AbstractFactory.h"


void
createUI(const AbstractGUIFactory* factory) {
    const Button* button = factory->createButton();
    const TextField* text_field = factory->createTextField();

    button->paint();
    text_field->paint();
}


int main() {
    AbstractGUIFactory* factory = new WindowsFactory();
    createUI(factory);
    delete factory;


    factory = new MacOsFactory();
    createUI(factory);
    delete factory;

}