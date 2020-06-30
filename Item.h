#pragma once
#include <iostream>
#include <string>
class Item
{
public:
	std::string sItemName;
	int iItemQuantitySold;
	double dItemPrice;
	static int iNumberOfItems;

	Item();
	Item(std::string sInit, int iInit, double dInit);
	Item(const Item &objSource);
	~Item();

	static int Number_of_Items();
};

