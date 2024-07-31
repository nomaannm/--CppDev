#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include <iostream>

/*
 * Provides an interface for creating families of related or dependent objects without specifying their concrete classes.
 * Abstract factory is used when we have to work with various families of related products.
 */

//Abstract Product
class Button {
public:
       virtual ~Button()= default;
       virtual void paint() const = 0;
};

class WindowsButton final : public Button {
public:
        void paint() const override {
            std::cout << "Rendering a Windows OS style button!\n";
        }
};

class MacOsButton final : public Button {
public:
        void paint() const override {
            std::cout << "Rendering a Mac OS style button!\n";
        }
};

class TextField {
public:
        virtual ~TextField() = default;
        virtual void paint() const = 0;
};

class WindowsTextField final : public TextField {
public:
        void paint() const override {
                std::cout << "Rendering a Windows Style Text Field!\n";
        }
};

class MacOsTextField final : public TextField {
public:
        void paint() const override {
                std::cout << "Rendering a Mac OS style text field!\n";
        }
};



// AbstractFactory
class AbstractGUIFactory {
public:
        virtual ~AbstractGUIFactory() = default;
        [[nodiscard]] virtual Button* createButton() const = 0;
        [[nodiscard]] virtual TextField* createTextField() const = 0;
};

class WindowsFactory final : public AbstractGUIFactory {
public:
        [[nodiscard]] Button* createButton() const override {
                return new WindowsButton();
        }
        [[nodiscard]] TextField* createTextField() const override {
                return new WindowsTextField();
        }
};

class MacOsFactory final : public AbstractGUIFactory {
public:
        [[nodiscard]] Button* createButton() const override {
                return new MacOsButton();
        }
        [[nodiscard]] TextField* createTextField() const override {
                return new MacOsTextField();
        }
};



#endif //ABSTRACTFACTORY_H
