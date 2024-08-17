#ifndef STATE_H
#define STATE_H
#include<string>
#include<iostream>

/*
 * State is a behavioral design pattern that lets an object alter its behavior when its internal state changes.
 * It appears as if the object changed its class. The State pattern is closely related to the concept
 * of a Finite-State Machine
 * The State pattern suggests that you create new classes for all possible states of an object and extract all
 * state-specific behaviors into these classes.
 * Instead of implementing all behaviors on its own, the original object, called context, stores a reference to
 * one of the state objects that represents its current state, and delegates all the state-related work to that object.
 * The buttons and switches in your smartphone behave differently depending on the current state of the device:
 *     When the phone is unlocked, pressing buttons leads to executing various functions.
 *     When the phone is locked, pressing any button leads to the unlock screen.
 *     When the phone’s charge is low, pressing any button shows the charging screen.
 */

// State interface
class PlayerState {
public:
    virtual ~PlayerState() = default;
    virtual void handleInput() = 0;
    virtual void update() = 0;

};

// Concrete States
class OnFootState final : public PlayerState {
public:
    void handleInput() override {
        std::cout << "On Foot: Player can walk, run, jump, or engage in combat." << std::endl;
    }

    void update() override {
        std::cout << "On Foot: Check for interactions with the environment or NPCs." << std::endl;
    }
};

class InVehicleState final : public PlayerState {
public:
    void handleInput() override {
        std::cout << "In Vehicle: Player can drive, shoot from the vehicle, or exit." << std::endl;
    }

    void update() override {
        std::cout << "In Vehicle: Update vehicle speed, direction, and check for collisions." << std::endl;
    }
};

class WantedState final : public PlayerState {
public:
    void handleInput() override {
        std::cout << "Wanted: Player must evade the police or engage in combat with law enforcement." << std::endl;
    }

    void update() override {
        std::cout << "Wanted: Increase police presence, track player's location, and manage wanted level." << std::endl;
    }
};

// Context Class
class Player {
private:
    PlayerState* currentState;

public:
    explicit Player(PlayerState* state) : currentState(state) {}

    void setState(PlayerState* state) {
        currentState = state;
    }

    void handleInput() const {
        currentState->handleInput();
    }

    void update() const {
        currentState->update();
    }
};

#endif //STATE_H
