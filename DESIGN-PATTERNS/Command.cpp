#include "Command.h"

int main() {
    auto light = std::make_shared<Light>();
    auto lightsOn = std::make_shared<LightOnCommand>(light);
    auto lightsOff = std::make_shared<LightOffCommand>(light);

    RemoteControl rc;
    rc.setCommand(lightsOn);
    rc.pressButton();

    rc.setCommand(lightsOff);
    rc.pressButton();

    return 0;
}
