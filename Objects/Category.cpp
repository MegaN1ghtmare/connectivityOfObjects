#include "Category.hpp"

Category::Category(const std::string& cName) {
    this->categoryName = cName;
    this->itemList = new std::map<std::string, Item*>;
}

Category::~Category() {

}

const std::string& Category::getCategoryName() const {
    return this->categoryName;
}

int Category::getItemsNumber() const {
    return itemList->size();
}

void Category::addItemToList(Item& item) {
    this->itemList->insert(std::pair<std::string, Item*>(item.getItemName(), &item));
}

void Category::createNewItem(const std::string& iName, int iQuant, int iPrice) {
    Item* item = new Item(iName, iQuant, iPrice, this);
    addItemToList(*item);
}

void Category::deleteItemFromCategory(Item& item) {
    this->itemList->erase(item.getItemName());
}

void Category::moveItemToAnotherCategory(Item& item, ICategory& newCategory) {
    deleteItemFromCategory(item);
    newCategory.addItemToList(item);
}

void Category::clearList() {
    for ( auto rit = itemList->rbegin(); rit != itemList->rend(); ) {
        Item* item = rit->second;

        item->deleteThisItem();
    }
}

std::map<std::string, Item*>& Category::getListOfItems() const {
    return *itemList;
}

template<typename First, typename Second>
std::ostream& operator<<(std::ostream& out, const std::map<First, Second>& lst) {
    typename std::map<First, Second>::const_iterator it = lst.begin();

    for ( int i = 1; it != lst.end(); it++, i++ ) {
        out << i << ". " << *(it->second);
    }

    return out;
}

std::ostream& operator<<(std::ostream& out, const Category& category) {
    out << "Category name: " << category.getCategoryName()
        << " it contains " << category.getItemsNumber() << " different items, "
        << " here is the list: " << std::endl << category.getListOfItems();

    return out;
}
