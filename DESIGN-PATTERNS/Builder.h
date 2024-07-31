#ifndef BUILDER_H
#define BUILDER_H
#include<cassert>
#include <iostream>
#include <string>
/*
 * Separates the construction of a complex object from its representation so that the same construction process can create different representations.
 * This pattern is very useful when our objects have several different components, which all need to come together for instantiation.
 */

class Person {
public:
       std::string name;
       int age{};
       std::string address;

       void print() const {
           std::cout << "Person details : \n";
           std::cout << "\tName : " << this->name ;
           std::cout << "\n\tAge : " << this->age ;
           std::cout << "\n\tAddress : " << this->address;
       }
};

class PersonBuilder {
public:
        virtual ~PersonBuilder() = default;
        virtual void setName(const std::string& _name) = 0;
        virtual void setAge(const int& _age) = 0;
        virtual void setAddress(const std::string& _address) = 0;
        [[nodiscard]] virtual Person* getResult() = 0;
};
class ConcretePersonBuilder final : public PersonBuilder {
private:
        Person* person{};
public:
        ConcretePersonBuilder() {
                this->reset();
        }
        ~ConcretePersonBuilder() override {
                delete person;
        }

        void reset() {
                this->person = new Person();
        }

        void setName(const std::string &_name) override {
                this->person->name = _name;
        }

        void setAge(const int &_age) override {
                this->person->age = _age;
        }

        void setAddress(const std::string &_address) override {
                this->person->address = _address;
        }

        [[nodiscard]] Person* getResult() override {
                Person* result = this->person;
                this->reset(); //Prepares for next person;
                return result;
        }

};

class PersonDirector {
private:
        PersonBuilder* builder;
public:
        void setBuilder(PersonBuilder* builder) {
                this->builder = builder;
        }

        void constructSimplePerson(const std::string& name, int age, const std::string& address ) const {
                this->builder->setName(name);
                this->builder->setAge(age);
                this->builder->setAddress(address);
        }
};


#endif //BUILDER_H
