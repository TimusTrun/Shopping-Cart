#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"
void PrintMenu(const ShoppingCart cart){ 
    cout << endl << "MENU" << endl << "a - Add item to cart" << endl << "d - Remove item from cart" << endl << "c - Change item quantity" << endl << "i - Output items' descriptions" << endl << "o - Output shopping cart" << endl << "q - Quit" << endl << endl << "Choose an option:" << endl;    
}

int main(){
    string custName;
    string currDate;
    string option;
    ItemToPurchase newItem;
    string iName;
    string iDesc;
    int iPrice;
    int iQuantity;
    string rItemName;
    ItemToPurchase modifyI;
    string mItemName;
    int mItemQ;
    cout << "Enter customer's name:" << endl;
    getline (cin, custName);
    cout << "Enter today's date:" << endl;
    getline (cin, currDate);
    ShoppingCart newCart = ShoppingCart(custName, currDate);
    cout << endl << "Customer name: " << newCart.GetCustomerName() << endl
         << "Today's date: " << newCart.GetDate() << endl;
    
    PrintMenu(newCart);
    cin >> option;
    while (option != "a" && option != "d" && option != "c" && option != "i" && option != "o" && option != "q"){
        cout << "Choose an option:" << endl;
        cin >> option;
    }
    
    while (option != "q"){
        if (option != "a" && option != "d" && option != "c" && option != "i" && option != "o"){
            cout << "Choose an option:" << endl;
            cin >> option;
        }
        if (option == "o"){
            cout << "OUTPUT SHOPPING CART" << endl;
            newCart.PrintTotal();
        }
        else if (option == "i"){
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            newCart.PrintDescriptions();
        }
        else if (option == "a"){
            cout << "ADD ITEM TO CART" << endl << "Enter the item name:" << endl;
            cin.ignore();
            getline(cin,iName);
            cout << "Enter the item description:" << endl;
//             cin.ignore();
            getline(cin,iDesc);
            cout << "Enter the item price:" << endl;
            cin >> iPrice;
            cout << "Enter the item quantity:" << endl;
            cin >> iQuantity;
            newItem = ItemToPurchase(iName, iDesc, iPrice, iQuantity);
            newCart.AddItem(newItem);
        }
        else if (option == "d"){
            cout << "REMOVE ITEM FROM CART" << endl << "Enter name of item to remove:" << endl;
            cin.ignore();
            getline(cin,rItemName);
            newCart.RemoveItem(rItemName);
        }
        else if (option == "c"){
            cout << "CHANGE ITEM QUANTITY" << endl << "Enter the item name:" << endl;
            cin.ignore();
            getline(cin,mItemName);
            cout << "Enter the new quantity:" << endl;
            cin >> mItemQ;
            modifyI.SetName(mItemName);
            modifyI.SetQuantity(mItemQ);
            newCart.ModifyItem(modifyI);
        }
        else
            exit(0);
        
        PrintMenu(newCart);
        cin >> option;
    }
}