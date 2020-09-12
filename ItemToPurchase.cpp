#include <iostream>
#include "ItemToPurchase.h"

//  private:
//      string itemName = "none";
//      string itemDesc = "none";
//      int itemPrice = 0;
//      int itemQuantity = 0;
//  public:
//      ItemToPurchase(string n, string d, int p, int q);
//      void SetName(const string&);
//      string GetName() const;
//      void SetPrice(const int&);
//      int GetPrice() const;
//      void SetQuantity(const int&);
//      int GetQuantity() const;
//      void SetDescription(const string&);
//      string GetDescription() const;
//      void PrintItemCost() const;
//      void PrintItemDescription() const;
//      int operator+(const ItemToPurchase& rhs) const;

ItemToPurchase::ItemToPurchase(){
    itemName = "none";
    itemDesc = "none";
    itemPrice = 0;
    itemQuantity = 0;
}
ItemToPurchase::ItemToPurchase(string n, string d, int p, int q){
    itemName = n;
    itemDesc = d;
    itemPrice = p;
    itemQuantity = q;
}
void ItemToPurchase::SetName(const string& n){
    this->itemName = n;
}
void ItemToPurchase::SetPrice(const int& p){
    this->itemPrice = p;
}
void ItemToPurchase::SetQuantity(const int& q){
    this->itemQuantity = q;
}
void ItemToPurchase::SetDescription(const string& d){
    itemDesc = d;
}
string ItemToPurchase::GetName() const{
    return itemName;
}
int ItemToPurchase::GetPrice() const{
    return itemPrice;
}
int ItemToPurchase::GetQuantity() const{
    return itemQuantity;
}
string ItemToPurchase::GetDescription() const{
    return itemDesc;
}
void ItemToPurchase::PrintItemCost() const{
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << (itemPrice * itemQuantity) << endl; 
 }
void ItemToPurchase::PrintItemDescription() const{
    cout << itemName << ": " << itemDesc << endl;
}
int ItemToPurchase::operator+(const ItemToPurchase& rhs) const{
    int totalP1 = rhs.GetQuantity() * rhs.GetPrice(); 
    int totalP2 = this->GetQuantity() * this->GetPrice();
    return totalP1 + totalP2;
}

bool ItemToPurchase::operator!=(const ItemToPurchase& rhs) const{
    bool notSame = true;
    if ((itemDesc == rhs.itemDesc) && (itemPrice == rhs.itemPrice) && (itemQuantity == rhs.itemQuantity)){
        notSame = false;
    }
    return notSame;
}
