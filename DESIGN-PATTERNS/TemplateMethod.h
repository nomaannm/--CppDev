#ifndef TEMPLATEMETHOD_H
#define TEMPLATEMETHOD_H
#include <iostream>

/*
 * Template Method is a behavioral design pattern that defines the skeleton of an algorithm in the superclass but lets
 * subclasses override specific steps of the algorithm without changing its structure.
 * The Template Method pattern suggests that you break down an algorithm into a series of steps, turn these steps into
 * methods, and put a series of calls to these methods inside a single template method. The steps may either be abstract,
 * or have some default implementation. To use the algorithm, the client is supposed to provide its own subclass, implement
 * all abstract steps, and override some of the optional ones if needed (but not the template method itself)
 */

//Abstract class
class Beverage {
public:
    // Template Method
    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();

    }
protected:
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    static void boilWater() {
        std::cout << "Boiling water!" << std::endl;
    }
    static void pourInCup() {
        std::cout << "Pouring into a cup!" << std::endl;

    }
};

// Concrete Subclass
class Tea  final : public Beverage {
protected:
    void brew() override {
        std::cout << "Steeping the tea" << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding lemon" << std::endl;
    }
};

// Another Concrete Subclass
class Coffee final : public Beverage {
protected:
    void brew() override {
        std::cout << "Dripping coffee through filter" << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding sugar and milk" << std::endl;
    }
};



#endif //TEMPLATEMETHOD_H
