#include "Item.hpp"

Item::Item(const std::string& iName, int iQuant, int iPrice) {
    this->itemName = iName;
    this->itemQuantity = iQuant;
    this->itemPrice = iPrice;
    this->currentCategory = ;
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

        void Item::addItemToOrder(Order& order);
        void Item::removeItemFromOrder(Order& order);

        std::map<std::string, Order*>& Item::getListOfORders() const;
