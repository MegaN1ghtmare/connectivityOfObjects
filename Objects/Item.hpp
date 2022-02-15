#ifndef ITEM_HPP
#define ITEM_HPP

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
        Item(const std::string& iName, int iQuant, int iPrice);
        virtual ~Item();

        virtual const std::string& getItemName() const;
        virtual int getItemQuantity() const;
        virtual int getItemPrice() const;
        virtual Category* getCategory() const;
        virtual Category& getCategoryRef() const;
        virtual const std::string& getItemsCategoryName() const;

        virtual void changeItemName(std::string& newItemName);
        virtual void setItemQuantity(int newQuantity);
        virtual void setItemPrice(int newPrice);

        virtual void addItemToOrder(Order& order);
        virtual void removeItemFromOrder(Order& order);

        virtual std::map<std::string, Order*>& getListOfORders() const;
};

#endif //ITEM_HPP
