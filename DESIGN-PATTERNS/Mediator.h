#ifndef MEDIATOR_H
#define MEDIATOR_H
#include <iostream>
#include<string>
/*
 * Mediator is a behavioral design pattern that lets you reduce chaotic dependencies between objects. The pattern restricts
 * direct communications between the objects and forces them to collaborate only via a mediator object.
 */

class ATCMediator;

class Aircraft {
private:
    std::string name_;
    ATCMediator* mediator_;
public:
    Aircraft(const std::string& name, ATCMediator* med) : name_{std::move(name)}, mediator_{std::move(med)} {};

    std::string getName() const {
        return name_;
    }
    void requestLanding() {
        std::cout << name_ << " requesting landing.\n";
        mediator_->notify(this, "requestLanding");
    }

    void requestTakeoff() {
        std::cout << name_ << " requesting takeoff.\n";
        mediator_->notify(this, "requestTakeoff");
    }

    void land() {
        std::cout << name_ << " is landing.\n";
        mediator_->setRunwayStatus(false); // Runway is now occupied.
    }

    void takeoff() {
        std::cout << name_ << " is taking off.\n";
        mediator_->setRunwayStatus(false); // Runway is now occupied.
    }

    void clearRunway() {
        std::cout << name_ << " has cleared the runway.\n";
        mediator_->setRunwayStatus(true); // Runway is now free.
    }
};

class ATCMediator {
public:
        virtual ~ATCMediator() = default;
        virtual bool isRunwayFree() const = 0;
        virtual void setRunwayStatus(bool status) = 0;
        virtual void notify(Aircraft* aircraft, std::string event) const = 0;
};

class ConcreteATCMediator final : public ATCMediator {
private:
    bool runwayFree;
public:
    ConcreteATCMediator() : runwayFree(true) {}

    bool isRunwayFree() const override {
        return runwayFree;
    }

    void setRunwayStatus(const bool status) override {
        runwayFree = status;
    }

    void notify(Aircraft *aircraft, std::string event) const override {
        if(event == "RequestLanding") {
            if(isRunwayFree()) {
                std::cout << aircraft->getName() << " is cleared to land.\n";
                aircraft->land();
            }
            else {
                std::cout << aircraft->getName() << " is instructed to hold.\n";
            }
        } else if(event == "requestTakeOff") {
            if(isRunwayFree()) {
                std::cout << aircraft->getName() << " is cleared for takeoff.\n";
                aircraft->takeoff();
            } else {
                std::cout << aircraft->getName() << " is instructed to hold.\n";
            }
        } else {
            std::cout << aircraft->getName() << " is instructed to hold.\n";

        }
    }
};





#endif //MEDIATOR_H
