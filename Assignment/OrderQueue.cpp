#include "OrderQueue.h"

OrderQueue::OrderQueue()
{
	firstNode = NULL;
	lastNode = NULL;
}

bool OrderQueue::isEmpty()
{
	if (firstNode == NULL)
	{
		return true;
	}
	return false;
}


bool OrderQueue::Enqueue(string cust, ItemList items)
{
	if (items.firstNode == NULL)
	{
		cout << "Your order is empty";
		return false;
	}
	Order* order = new Order;
	order->user = cust;
	order->itemList = items;
	order->status = "Preparing";
	order->next = NULL;


	if (isEmpty() == true)
	{
		firstNode = order;
		lastNode = order;
		return true;

	}
	else
	{
		lastNode->next = order;
		lastNode = lastNode->next;
		return true;
	}
}