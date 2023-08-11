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


bool OrderQueue::enqueue(string cust, ItemList items)
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

bool OrderQueue::dequeue() {
	if (isEmpty()) {
		return false;
	}
	if (firstNode == lastNode) {
		delete firstNode;
		firstNode = NULL;
		lastNode = NULL;
	}
	else {
		Order* temp = new Order;
		temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
	}
	return true;
}

void OrderQueue::listOrders(FoodList foodList) {
	if (isEmpty()) {
		return;
	}
	Order* temp = new Order;
	temp = firstNode;
	while (temp != nullptr) {
		cout << "User: " << temp->user << "\tStatus: " << temp->status << "\nOrdered Items: \n";
		temp->itemList.PrintAll(foodList);
		temp = temp->next;
	}
}