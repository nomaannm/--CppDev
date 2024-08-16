#include "Mediator.h"

int main() {
    ConcreteATCMediator* atc = new ConcreteATCMediator();

    Aircraft* flight1 = new Aircraft("Flight 101", atc);
    Aircraft* flight2 = new Aircraft("Flight 202", atc);

    flight1->requestLanding();
    flight2->requestLanding();

    flight1->clearRunway();
    flight2->requestLanding();

    flight2->clearRunway();
    flight1->requestTakeoff();

    flight1->clearRunway();

    delete flight1;
    delete flight2;
    delete atc;

    return 0;
}

