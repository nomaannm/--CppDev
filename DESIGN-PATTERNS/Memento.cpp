#include "Memento.h"

int main() {
    Originator originator;
    Caretaker caretaker;

    originator.setState("State1");
    caretaker.add(originator.saveStateToMemento());

    originator.setState("State2");
    caretaker.add(originator.saveStateToMemento());

    originator.setState("State3");

    originator.getStateFromMemento(caretaker.get(0));
    originator.getStateFromMemento(caretaker.get(1));

    return 0;
}
