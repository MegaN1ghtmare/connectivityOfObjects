#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
#include <map>

#include "../Interfaces/IItem.hpp"
#include "Category.hpp"

class Order;
class Category;

class Item: public IItem {
    protected:
        std::string itemName;
        int itemQuantity;
        int itemPrice;
        Category* currentCategory;
    public:
        Item(const std::string& iName, int iQuant, int iPrice, Category* category);
        virtual ~Item();

        const std::string& getItemName() const;
        int getItemQuantity() const;
        int getItemPrice() const;
        Category* getCategory() const;
        Category& getCategoryRef() const;
        const std::string& getItemsCategoryName() const;

        virtual void changeItemName(std::string& newItemName);
        virtual void setItemQuantity(int newQuantity);
        virtual void setItemPrice(int newPrice);
        virtual void changeItemCategory(Category& newCategory);
        virtual void deleteThisItem();

        virtual void addItemToOrder(Order& order);
        virtual void removeItemFromOrder(Order& order);

        // virtual std::map<std::string, Order*>& getListOfORders() const;
};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif //ITEM_HPP
