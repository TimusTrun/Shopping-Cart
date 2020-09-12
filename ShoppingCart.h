#ifndef __SHOPPINGCART_H__
#define __SHOPPINGCART_H__
#include "ItemToPurchase.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class ShoppingCart{
   private:
    string customerName = "none";
    string currentDate = "January 1, 2016";
    vector<ItemToPurchase> cartItems;
   public:
    ShoppingCart();
    ShoppingCart(string cn, string date);
    string GetCustomerName() const;
    string GetDate() const;
    void AddItem(const ItemToPurchase& itp);
    void RemoveItem(const string& ri);
    void ModifyItem(const ItemToPurchase& mi);
    int GetNumItemsInCart() const;
    int GetCostOfCart() const;
    void PrintTotal() const;
    void PrintDescriptions() const;
};

#endif