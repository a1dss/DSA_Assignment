#pragma once
#include <iostream>
#include <string>
#include "FoodList.h"

using namespace std;

class OrderItems
{
	struct Item
	{
		int ID;
		int Qty;
		Item* next;
	};

private:
	Item* firstNode;
public:


	//constructor
	OrderItems();

	//deconstructor
	//~OrderItems();


	//Check if empty
	bool IsEmpty();

	//Add Item to list
	//Prequisite: id must exist in foodlist
	bool AddtoList(int id, int qty, FoodList foodlist);

	//Calculate total price
	double CalculateTotal(FoodList foodlist);

	//Show current items
	void PrintAll(FoodList foodlist);
};
