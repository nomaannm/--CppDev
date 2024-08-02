#include "Facade.h"

int
main() {

    HomeTheatorFacade::watchMovie("Dunkirk");
    std::cout << "Enjoyed the movie!\n";
    HomeTheatorFacade::endMovie();


}