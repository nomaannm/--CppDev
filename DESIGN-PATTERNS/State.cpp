#include "State.h"

int main() {
    OnFootState onFoot;
    InVehicleState inVehicle;
    WantedState wanted;

    Player player(&onFoot);
    player.handleInput();  // Output: On Foot: Player can walk, run, jump, or engage in combat.
    player.update();       // Output: On Foot: Check for interactions with the environment or NPCs.

    player.setState(&inVehicle);
    player.handleInput();  // Output: In Vehicle: Player can drive, shoot from the vehicle, or exit.
    player.update();       // Output: In Vehicle: Update vehicle speed, direction, and check for collisions.

    player.setState(&wanted);
    player.handleInput();  // Output: Wanted: Player must evade the police or engage in combat with law enforcement.
    player.update();       // Output: Wanted: Increase police presence, track player's location, and manage wanted level.

    return 0;
}