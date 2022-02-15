#ifndef IITEM_HPP
#define IITEM_HPP

#include <string>
#include <map>

class Order;

class IItem {
    public:
        IItem();
        virtual ~IItem();

        virtual void changeItemName(std::string& newItemName) = 0;
        virtual void setItemQuantity(int newQuantity) = 0;
        virtual void setItemPrice(int newPrice) = 0;
        virtual void deleteThisItem() = 0;

        virtual void addItemToOrder(Order& order) = 0;
        virtual void removeItemFromOrder(Order& order) = 0;

        virtual std::map<std::string, Order*>& getListOfORders() const = 0;
};

#endif //IITEM_HPP
