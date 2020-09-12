#ifndef __ITEMTOPURCHASE_H__
#define __ITEMTOPURCHASE_H__

#include <string>
using namespace std;

class ItemToPurchase{
    private:
        string itemName = "none";
        string itemDesc = "none";
        int itemPrice = 0;
        int itemQuantity = 0;
    public:
        ItemToPurchase();
        ItemToPurchase(string n, string d, int p, int q);
        void SetName(const string&);
        string GetName() const;
        void SetPrice(const int&);
        int GetPrice() const;
        void SetQuantity(const int&);
        int GetQuantity() const;
        void SetDescription(const string&);
        string GetDescription() const;
        void PrintItemCost() const;
        void PrintItemDescription() const;
        int operator+(const ItemToPurchase& rhs) const;
        bool operator!=(const ItemToPurchase& rhs) const;
};

#endif