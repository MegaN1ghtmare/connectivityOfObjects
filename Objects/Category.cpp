#include "Category.hpp"

Categoty::Category(const std::string& cName) {
    this->categoryName = cName;
    this->itemList = new std::map<std::string, Item*>;
    this->itemCounter = 0;
}

Categoty::~Category() {
    delete(this->categoryName);
    delete(this->itemList);
}

const std::string& Categoty::getCategoryName() const {
    return this->categoryName;
}

int Categoty::getItemCounter() const {
    return this->itemCounter;
}

void Categoty::increaseItemCounter() {
    this->itemCounter += 1;
}

void Categoty::decreaseItemCounter() {
    this->itemCounter -= 1;
}

void Categoty::addItemToList(Item& item) {
    this->itemList->insert(std::pair<std::string, Item*>(item.getItemName(), &item));
    increaseItemCounter();
}

void Categoty::createNewItem(const std::string& iName, int iQuant, int iPrice) {
    Item item(iName, iQuant, iPrice);
    addItemToList(item);
}

void Item::deleteItemFromCategoty(Item& item) {
    this->itemList->erase(item.getItemName());
    decreaseItemCounter();
}

void Categoty::moveItemToAnotherCategory(Item& item, Categoty& newCategory) {
    deleteItemFromCategoty(item);
    newCategory.addItemToList(item);
}

void Categoty::clearList() {
    for ( auto it = itemList->begin(); it != itemList->end(); it++ ) {
        Item* item = it->second;

        item->deleteThisItem();
    }
}

std::map<std::string, Item*>& Categoty::getListOfItems() const {
    return *itemList;
}

template<typename First, typename Second>
std::ostream& operator<<(std::ostream& out, const std::map<First, Second>& lst) {
    typename std::map<First, Second>::const_iterator it = lst.begin();

    for ( int i = 1; it != lst.end(); it++, i++ ) {
        out << i << ". " << it->second << std::endl;
    }

    return out;
}

std::ostream& operator<<(std::ostream& out, const Category& category) {
    out << "Category name: " << category.getCategoryName()
        << " it contains " << category.getItemCounter() << " different items, "
        << " here is the list: " << category.getListOfItems() << std::endl;

    return out;
}
