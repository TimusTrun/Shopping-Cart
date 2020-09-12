#include "ShoppingCart.h"
//   private:
//     string customerName = "none";
//     string currentDate = "January 1, 2016";
//     vector<ItemToPurchase> cartItems;
//    public:
//     ShoppingCart();
//     ShoppingCart(string cn, string date);
//     string GetCustomerName() const;
//     string GetDate() const;
//     void AddItem(const ItemToPurchase& itp);
//     void RemoveItem(const string& ri);
//     void ModifyItem(const ItemToPurchase& mi);
//     int GetNumItemsInCart() const;
//     int GetCostOfCart() const;
//     void PrintTotal() const;
//     void PrintDescriptions() const;

ShoppingCart::ShoppingCart(){
    customerName = "none";
    currentDate = "January 1, 2016";
    vector<ItemToPurchase> cartItems;
}

ShoppingCart::ShoppingCart(string cn, string date){
    customerName = cn;
    currentDate = date;
    vector<ItemToPurchase> cartItems;    
}

string ShoppingCart::GetCustomerName() const{
    return customerName;
}

string ShoppingCart::GetDate() const{
    return currentDate;
}

void ShoppingCart::AddItem(const ItemToPurchase& itp){
    cartItems.push_back(itp);
}

void ShoppingCart::RemoveItem(const string& ri){
    bool itemNotFound = true; 
    for (unsigned i = 0; i < cartItems.size(); ++i){
        if (ri == cartItems.at(i).GetName()){
            itemNotFound = false;
            cartItems.erase(cartItems.begin()+i);
        }
    }
    if (itemNotFound)
    cout << "Item not found in cart. Nothing removed." << endl;
}

void ShoppingCart::ModifyItem(const ItemToPurchase& mi){
    bool itemNotFound = true;
    ItemToPurchase defaultItem;
    for (unsigned i = 0; i < cartItems.size(); ++i){
        if (mi.GetName() == cartItems.at(i).GetName()){
            itemNotFound = false;
            if (mi.GetPrice() != defaultItem.GetPrice())
                cartItems.at(i).SetPrice(mi.GetPrice());
            if (mi.GetQuantity() != defaultItem.GetQuantity())
                cartItems.at(i).SetQuantity(mi.GetQuantity());
            if (mi.GetDescription() != defaultItem.GetDescription())
                cartItems.at(i).SetDescription(mi.GetDescription());
        }
}
    if (itemNotFound){
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::GetNumItemsInCart() const{
    int numItem = 0;
    for (unsigned i = 0; i < cartItems.size(); ++i){
        numItem += cartItems.at(i).GetQuantity();
    }
    return numItem;
}

int ShoppingCart::GetCostOfCart() const{
    int costCart = 0;
    for (unsigned i = 0; i < cartItems.size(); ++i){
        costCart += (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
    }
    return costCart;
}

void ShoppingCart::PrintTotal() const{
    bool empty = true;
    if (cartItems.size() > 0){
        empty = false;
    }
    if (empty){
        cout << customerName << "'s Shopping Cart - " << currentDate << endl << "Number of Items: " << this->GetNumItemsInCart() << endl << endl;
        cout << "SHOPPING CART IS EMPTY" << endl;
        cout << endl << "Total: $" << this->GetCostOfCart() << endl;
    }
    else{
        cout << customerName << "'s Shopping Cart - " << currentDate << endl << "Number of Items: " << this->GetNumItemsInCart() << endl << endl;
        for (unsigned i = 0; i < cartItems.size(); ++i){
            cartItems.at(i).PrintItemCost();
        }
        cout << endl << "Total: $" << this->GetCostOfCart() << endl;
    }
}

void ShoppingCart::PrintDescriptions() const{
    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl << "Item Descriptions" << endl;
    
    for (unsigned i = 0; i < cartItems.size(); ++i){
        cartItems.at(i).PrintItemDescription();
    }
}

