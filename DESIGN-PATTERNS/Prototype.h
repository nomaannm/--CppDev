#ifndef PROTOTYPE_H
#define PROTOTYPE_H
#include <iostream>
#include <memory>
#include <unordered_map>

/*
 * The concept is to copy an exisiting object rather than creating a new instance from scratch, because creating new instance
 * may be costly. This approach solves costly resouces and time, expecially when object creation is a heavy process.
 * When a system should be independent of how its products are created, composed, and represented, then prototype pattern must be used.
 * Whnen you need to create objects at runtime based on a dynamic set of prototypes.
 */

class Prototype {
public:
      virtual ~Prototype() = default;
      [[nodiscard]] virtual std::unique_ptr<Prototype> clone() const = 0;
      virtual void show() const = 0;
};

template<typename T>
class ConcretePrototype1 final : public Prototype {
public:
    explicit ConcretePrototype1(const T &_value)
        : value(_value) {
    }
    [[nodiscard]] std::unique_ptr<Prototype> clone() const override {
              return std::make_unique<ConcretePrototype1>(*this);
    }
    void show() const override {
        std::cout << "Concrete Prototype 1 Value : " << this->value << "\n";
    }
private:
    T value;

};

class ConcretePrototype2 final : public Prototype {
private:
    std::string value;
public:
    explicit ConcretePrototype2(std::string _value) : value{_value} {

    }
    [[nodiscard]] std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<ConcretePrototype2>(*this);
    }
    void show() const override {
        std::cout << "Concrete Prototype 2 Value : " << this->value << "\n";
    }
};

class ProtoypesRegister {
private:
    std::unordered_map<std::string, std::unique_ptr<Prototype>> prototypes_ ;
public:
    void addPrototype(const std::string& key, std::unique_ptr<Prototype> prototype) {
        prototypes_[key] = std::move(prototype);
    }

    //Creating a clone of the protoype identified by key
    std::unique_ptr<Prototype> create(const std::string& key) const {
        if(prototypes_.find(key) != prototypes_.end()) {
            return prototypes_.at(key)->clone();
        }
        return nullptr;
    }


};





#endif //PROTOTYPE_H
