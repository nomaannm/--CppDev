#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <memory>
#include <utility>

//Command Interface
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() const = 0;
};

// Receiver
class Light {
public:
    void on() const {
        std::cout << "Light ON!\n";
    }
    void off() const {
        std::cout << "Light OFF!\n";
    }
};

//Concrete command for turning on the lights!
class LightOnCommand final : public Command {
public:
    explicit LightOnCommand(std::shared_ptr<Light> light) : _light{std::move(light)} {}
    void execute() const override {
        _light->on();
    }
private:
    std::shared_ptr<Light> _light;
};
//Concrete command for turning off the lights!
class LightOffCommand final : public Command {
public:
    explicit LightOffCommand(std::shared_ptr<Light> light) : _light{std::move(light)} {}
    void execute() const override {
        _light->off();
    }

private:
    std::shared_ptr<Light> _light;
};

//Invoker
class RemoteControl {
public:
    void setCommand(std::shared_ptr<Command> command) {
        command_ = std::move(command);
    }
    void pressButton() const {
        command_->execute();
    }


private:
    std::shared_ptr<Command> command_;
};



#endif //COMMAND_H
