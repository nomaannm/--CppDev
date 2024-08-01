#ifndef ADAPTER_H
#define ADAPTER_H
#include <iostream>
#include <memory>
#include <string>
#include <utility>

/*
 * Type A -> Type C USB Adapter, Ethernet -> HDMI cable adapters
 * The Adapter pattern is a structural design pattern that allows objects with incompatible interfaces to work together.
 * The Adapter acts as a bridge between the two interfaces, enabling them to communicate and collaborate.
 *
 * Key Concepts
       Target Interface: The interface that the client expects to work with.
       Adaptee: The existing interface that needs to be adapted.
       Adapter: The class that implements the Target interface and translates requests to the Adaptee interface.
 * USE CASES:
        When you want to use an existing class, but its interface is not compatible with the rest of your code.
        When you want to create a reusable class that cooperates with unrelated or unforeseen classes.
*/


//Target interface
class Logger {
public:
    virtual ~Logger() = default;
    virtual void log(const std::string& _log) const = 0;
};

//Adaptee class with an incompatible interface
class ThirdPartyLogger {
public:
    virtual ~ThirdPartyLogger() = default;
    auto writeLogs(const std::string &_logs) -> void { // NOLINT(*-convert-member-functions-to-static)
        std::cout << "Logs : " << _logs << std::endl;

    }
};

// The LoggerAdapter implements the Logger interface and translates the calls to ThirdPartyLogger
class LoggerAdapter : public Logger {
public:
    explicit LoggerAdapter(std::shared_ptr<ThirdPartyLogger> adaptee) : _adaptee(std::move(adaptee)){}

    void log(const std::string& _log) const override {
        this->_adaptee->writeLogs(_log);
    }
private:
    std::shared_ptr<ThirdPartyLogger> _adaptee;

};



#endif //ADPATER_H
