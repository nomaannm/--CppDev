#ifndef MEMENTO_H
#define MEMENTO_H
#include <iostream>
#include <string>
#include <vector>

/*
 * Memento is a behavioral design pattern that lets you save and restore the previous state of an object without revealing
 * the details of its implementation.
 * The Memento pattern is a behavioral design pattern used in software development to capture and restore the state of an
 * object without violating its encapsulation. It allows an object to save its internal state so that it can be restored
 * later, providing a way to implement undo/redo functionality.
 * Key Components of the Memento Pattern:
            Originator: The object whose state needs to be saved and restored. It creates a memento containing a snapshot
            of its current state.

            Memento: A value object that acts as a snapshot of the Originator's state. It is typically immutable and only
            the Originator has access to it. The Memento stores the internal state of the Originator.

            Caretaker: Manages the mementos, keeping track of the originator’s state history. It is responsible for
            requesting a Memento from the Originator, storing it, and possibly restoring the Originator's state from
            a Memento at a later time.
 */

class Memento {
private:
    std::string state_;
public:
    explicit Memento(const std::string& state) : state_{state} {}

    std::string getState() const {
        return state_;
    }

};


class Originator {
private:
    std::string state_;
public:
    void setState(const std::string& state) {
        this->state_ = state;
        std::cout << "State set to : " << state_ << std::endl;
    }

    Memento saveStateToMemento() const {
        return Memento(state_);
    }

    void getStateFromMemento(const Memento& memento) {
        state_ = memento.getState();
        std::cout << "State restored to : " << state_ << std::endl;

    }
};

class Caretaker {
private:
    std::vector<Memento> mementos;
public:
    void add(const Memento& state) {
        mementos.push_back(state);
    }

    Memento get(const int index) {
        return mementos[index];
    }
};



#endif //MEMENTO_H
