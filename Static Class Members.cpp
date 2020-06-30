// Static Class Members.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"

//Here I've created a regular function that displays the static variable of the Item class using the scope resolution operator ::
void Number_of_Items() 
{
    std::cout << Item::Number_of_Items() << std::endl;

}
//Here I am passing an object to a function to see if a new object is created
//I'm not expecting a new object to be created as I'm passing by reference as opposed to passing by value (copy)
void Display_Item_By_Reference(const Item &objItem) 
{
    std::cout << "Item name: " << objItem.sItemName << std::endl;
    std::cout << "Item price: " << objItem.dItemPrice << std::endl;
    std::cout << "Item quantity sold: " << objItem.iItemQuantitySold << std::endl;
}
//In this function I'm passing an object by copy so I'm expecting it to call the copy constructor in the Item class (one I explicitly created)

void Display_Item_By_Copy(const Item objItem) {

    std::cout << "Item name: " << objItem.sItemName << std::endl;
    std::cout << "Item price: " << objItem.dItemPrice << std::endl;
    std::cout << "Item quantity sold: " << objItem.iItemQuantitySold << std::endl;
}
int main()
{
    Number_of_Items(); //Expecting the number to be 0 as no items have been created at this point.
    Item Apple("Apple", 54, 1.3); 
    Item Orange("Orange", 76, 2.3);
    Item Pear ("Pear", 43, 2.2);

    Number_of_Items(); //Expecting the number to 3 as I've created 3 items at this point.

    Display_Item_By_Reference(Apple);
    Number_of_Items(); //I'm expecting the number to still say 3 as I've passed by reference.

    Display_Item_By_Copy(Apple);
    Number_of_Items();//Even though I've passed by copy I'm still expecting the number to be 3 as the destructor for the copy will be called.

    Item* ptrLemon = new Item("Lemon", 32, 89); 
    Number_of_Items(); //Here I'm creeating a new item dynamically on the heap so I'm expecting 4 to be displayed.
    delete ptrLemon;
    Number_of_Items(); //At this point the object I created dynamically on the heap has been deleted so I'm expecting it to say back to 3.
}