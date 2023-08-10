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
	if (foodlist.size<id or id<=0)
	{
		cout << "Invalid Input";
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
			currnode = currnode->next;
		}
		currnode->next = item;
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