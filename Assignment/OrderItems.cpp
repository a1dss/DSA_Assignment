#include "OrderItems.h"


OrderItems::OrderItems()
{
	firstNode = NULL;
}


bool OrderItems::IsEmpty()
{
	if (firstNode == NULL)
	{
		return true;
	}
	return false;
}


bool OrderItems::AddtoList(int id, int qty, FoodList foodlist)
{
	bool exists = false;
	if (foodlist.size<id or id<=0 or qty <=0)
	{
		cout << "Invalid Input\n";
		return false;
	}
	Item* item = new Item;
	item->ID = id;
	item->Qty = qty;
	item->next = NULL;
	if (IsEmpty() == true)
	{
		firstNode = item;

		return true;

	}
	else
	{
		Item* currnode = firstNode;
		while (currnode->next != NULL)
		{
			if (currnode->ID == id) {
				currnode->Qty += qty;
				exists = true;
			}
			currnode = currnode->next;
		}
		if (!exists) {
			currnode->next = item;
		}
		return true;
	}
}

void OrderItems::PrintAll(FoodList foodlist)
{
	cout << "Current items: " << endl;
	Item* currnode = firstNode;
	while (currnode != NULL)
	{
		cout << currnode->Qty << "\t" << foodlist.FoodArr[currnode->ID - 1].name << endl;
		currnode = currnode->next;
	}


}


double OrderItems::CalculateTotal(FoodList foodlist)
{
	double currtotal = 0;
	Item* currnode = firstNode;
	while (currnode != NULL)
	{
		currtotal += foodlist.FoodArr[currnode->ID -1].cost * currnode->Qty;
		currnode = currnode->next;
	}
	return currtotal;
}