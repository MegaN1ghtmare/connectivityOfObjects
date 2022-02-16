#include "Item.hpp"

Item::Item(const std::string& iName, int iQuant, int iPrice, Category* category) {
    this->itemName = iName;
    this->itemQuantity = iQuant;
    this->itemPrice = iPrice;
    this->currentCategory = category;
}

Item::~Item() {

}

const std::string& Item::getItemName() const {
    return this->itemName;
}

int Item::getItemQuantity() const{
    return this->itemQuantity;
}

int Item::getItemPrice() const{
    return this->itemPrice;
}

Category* Item::getCategory() const {
    return this->currentCategory;
}

Category& Item::getCategoryRef() const {
    return *(this->currentCategory);
}

const std::string& Item::getItemsCategoryName() const {
    return currentCategory->getCategoryName();
}

void Item::changeItemName(std::string& newItemName) {
    this->itemName = newItemName;
}

void Item::setItemQuantity(int newQuantity) {
    this->itemQuantity = newQuantity;
}

void Item::setItemPrice(int newPrice) {
    this->itemPrice = newPrice;
}

void Item::changeItemCategory(Category& newCategory) {
    this->currentCategory->moveItemToAnotherCategory(*this, newCategory);
}

void Item::deleteThisItem() {
    this->currentCategory->deleteItemFromCategory(*this);
    delete this;
}

void Item::addItemToOrder(Order& order) {

}

void Item::removeItemFromOrder(Order& order) {

}

// std::map<std::string, Order*>& Item::getListOfORders() const {

// }

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << "Item name: " << item.getItemName()
        << ", price: " << item.getItemPrice() << " dollars, "
        << "in stock: " << item.getItemQuantity() << " pcs" << std::endl;

    return out;
}
