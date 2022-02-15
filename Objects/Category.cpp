#include "Category.hpp"

Categoty::Category(const std::string& cName) {
    this->categoryName = cName;
    this->itemList = new std::map<std::string, Item*>;
}

Categoty::~Category() {

}

const std::string& Categoty::getCategoryName() const {
    return this->categoryName;
}

void Categoty::addItemToList(Item& item) {
    this->itemList->insert(std::pair<std::string, Item*>(item.getItemName(), &item));
}

void Categoty::createNewItem(const std::string& iName, int iQuant, int iPrice) {
    Item item(iName, iQuant, iPrice);
    addItemToList(item);
}

void Categoty::moveItemToAnotherCategory(Item& item, Categoty& newCategory) {
    this->itemList->erase(item.getItemName());
    newCategory.addItemToList(item);
}

        virtual void Categoty::clearList();

        virtual std::map<std::string, Item*>& Categoty::getListOfItems() const;
