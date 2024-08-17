#include "TemplateMethod.h"

int main() {
    Tea tea;
    Coffee coffee;

    std::cout << "Making tea:" << std::endl;
    tea.prepareRecipe();

    std::cout << "\nMaking coffee:" << std::endl;
    coffee.prepareRecipe();

    return 0;
}