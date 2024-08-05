#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
class Flyweight;
using SharedFlyweight = std::shared_ptr<Flyweight>;
/*
 * The Flyweight pattern is a structural design pattern aimed at reducing the memory footprint of an application by sharing objects that
 * are similar in nature. It’s particularly useful when you need to create a large number of objects that share common data but differ
 * in some attributes.
 * Components
   Flyweight: The interface that defines the methods for working with shared data. It can be either abstract or an interface, and it
   usually defines methods for managing intrinsic state.
   ConcreteFlyweight: Implements the Flyweight interface and represents the objects that can be shared. It stores the intrinsic state of
   the object.
   FlyweightFactory: Creates and manages flyweight objects. It ensures that flyweights are shared properly and that clients use shared
   instances whenever possible.
   Client: Uses the FlyweightFactory to obtain flyweight instances and maintains the extrinsic state of the object

 * Use Cases
   Graphics: When rendering a large number of objects that have the same appearance but differ in position or other attributes.
   Text Editors: When displaying a large number of characters or words where many characters are the same.
   Game Development: For managing large numbers of similar game objects efficiently.
 */

//Flyweight Interface
class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) const = 0;
    virtual ~Flyweight() = default;
};

class ConcreteFlyweight final : public Flyweight {
private:
    std::string intrinsicState;
public:
    explicit ConcreteFlyweight(const std::string& state) : intrinsicState{state} {}

    void operation(const std::string& extrinsicState) const override {
        std::cout << "Intrinsic State : " << intrinsicState << "\n";
        std::cout << "Extrinsic State : " << extrinsicState << "\n";
    }
};


class FlyweightFactory {
private:
    std::unordered_map<std::string, SharedFlyweight> flyweights;
public:
    SharedFlyweight getFlyweight(const std::string& key) {
        if(flyweights.find(key) == flyweights.end()) {
            flyweights[key] = std::make_shared<ConcreteFlyweight>(key);
        }
        return flyweights[key];
    }

};



#endif //FLYWEIGHT_H
