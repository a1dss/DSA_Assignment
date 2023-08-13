#pragma once
#include <iostream>
#include <string>
#include "FoodList.h"

using namespace std;

class OrderItems
{
private:

	//Linked list implementation
	struct Item
	{
		int ID;
		int Qty;
		Item* next;
	};


	Item* firstNode;
public:


	//constructor
	OrderItems();

	//deconstructor
	//~OrderItems();


	//Check if empty
	bool IsEmpty();

	//Add Item to list
	//Prequisite: id must exist in foodlist, qty > 0
	bool AddtoList(int id, int qty, FoodList foodlist);

	//Calculate total price and returns the value
	double CalculateTotal(FoodList foodlist);

	//Show current items
	void PrintAll(FoodList foodlist);
};
