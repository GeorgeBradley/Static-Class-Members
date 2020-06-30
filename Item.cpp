#include "Item.h"

int Item::iNumberOfItems = 0;
Item::Item()
:sItemName(""), iItemQuantitySold(0), dItemPrice(0)
{
	iNumberOfItems++;
}
Item::Item(std::string sInit, int iInit, double dInit)
	: sItemName(sInit), iItemQuantitySold(iInit), dItemPrice(dInit)
{
	iNumberOfItems++;
}

Item::Item(const Item& objSource)
	:Item(objSource.sItemName, objSource.iItemQuantitySold, objSource.dItemPrice)
{
}

Item::~Item() {

	--iNumberOfItems;
}

int Item::Number_of_Items() 
{
	return iNumberOfItems;
}