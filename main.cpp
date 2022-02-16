// #include "Interfaces/*.hpp"
#include "Objects/Category.hpp"
#include "Objects/Item.hpp"

int main() {
    Category category("Mobilephones");
    std::cout << "Category Mobilephones created:" << std::endl;
    std::cout << category << std::endl;

    category.createNewItem("IPhone 13 128Gb", 10, 1300);
    category.createNewItem("IPhone 12 64Gb", 5, 1000);
    category.createNewItem("Xiaomi MI Note 11", 12, 500);
    category.createNewItem("Samsung S22", 9, 1100);

    std::cout << "Mobilephones items created:" << std::endl;
    std::cout << category << std::endl;

    Item ittem("Samsung S9+", 1, 300, &category);
    std::cout << ittem << std::endl;
    category.addItemToList(ittem);
    std::cout << category << std::endl;
}
