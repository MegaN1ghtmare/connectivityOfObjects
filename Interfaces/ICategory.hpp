#ifndef ICATEGORY_HPP
#define ICATEGORY_HPP

#include <string>
#include <map>

class Item;

class ICategory {
    public:
        ICategory();
        virtual ~ICategory();

        virtual void addItemToList(Item& item) = 0;
        virtual void createNewItem(const std::string& iName, int iQuant, int iPrice) = 0;
        virtual void deleteItemFromCategoty(Item& item) = 0;
        virtual void moveItemToAnotherCategory(Item& item, Categoty& newCategory) = 0;
        virtual void clearList() = 0;

        virtual std::map<std::string, Item*>& getListOfItems() const = 0;
};

#endif //ICATEGORY_HPP
