#ifndef CATEGORY_HPP
#define CATEGORY_HPP

#include <iostream>
#include <string>
#include <map>

#include "../Interfaces/ICategory.hpp"
#include "Item.hpp"

class Item;

class Category: public ICategory {
    protected:
        std::string categoryName;
        std::map<std::string, Item*>* itemList;
        int itemCounter;
    public:
        Category(const std::string& cName);
        virtual ~Category();

        const std::string& getCategoryName() const;
        int getItemCounter() const;

        void increaseItemCounter();
        void decreaseItemCounter();

        virtual void addItemToList(Item& item);
        virtual void createNewItem(const std::string& iName, int iQuant, int iPrice);
        virtual void deleteItemFromCategory(Item& item);
        virtual void moveItemToAnotherCategory(Item& item, ICategory& newCategory);
        virtual void clearList();

        virtual std::map<std::string, Item*>& getListOfItems() const;
};

std::ostream& operator<<(std::ostream& out, const Category& category);

#endif //CATEGORY_HPP
