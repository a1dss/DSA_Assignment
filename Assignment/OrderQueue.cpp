// Team Member 1: Aidan Toh Qun Kai, S10243503 
// Team Member 2: Goh Bing Lo, S10242470

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

	Order* order = new Order;
	order->user = cust;
	order->itemList = items;
	order->status = "In Queue";
	order->next = NULL;


	if (isEmpty() == true)
	{
		order->status = "Preparing";
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
	if (isEmpty() || firstNode->status == "Preparing") {
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
		while (firstNode->status == "Cancelled")
		{
			firstNode = firstNode->next;
		}
		firstNode->status = "Preparing";
		delete temp;
	}
	return true;
}

string OrderQueue::getStatus(int pos)
{
	Order* currnode = firstNode;
	for (int i = 0; i < pos; i++)
	{
		currnode = currnode->next;
	}
	return currnode->status;
}


void OrderQueue::updateStatus(string s)
{
	firstNode->status = s;
}

void OrderQueue::cancelOrder(string user, int pos)
{
	Order* currnode = firstNode;
	for (int i = 1; i < pos; i++)
	{
		if (currnode== nullptr)
		{
			cout << "Invalid Order" << endl;
			return;
		}

		currnode = currnode->next;

	}
	if (currnode->user != user || currnode->status == "Completed")
	{
		cout << "Invalid Order" << endl;
	}
	else
	{
		currnode->status = "Cancelled";
	}
}


void OrderQueue::listOrders(FoodList foodList) {
	if (isEmpty()) {
		return;
	}
	Order* temp = new Order;
	temp = firstNode;
	int i = 1;
	while (temp != nullptr) {
		cout << endl;
		cout << "Order No: " << i << "    User: " << temp->user << "\tStatus: " << temp->status << endl;
		temp->itemList.PrintAll(foodList);
		temp = temp->next;
		i++;
	}

}


bool OrderQueue::listOrders(string user, FoodList foodList)
{

	Order* temp = new Order;
	temp = firstNode;
	int i = 1;
	int check = 0;
	while (temp != nullptr) {
		if (temp->user == user)
		{
			cout << endl;
			cout << "Order No: " << i << "    User: " << temp->user << "\tStatus: " << temp->status << endl;
			temp->itemList.PrintAll(foodList);
			check++;

		}

		temp = temp->next;
		i++;
	}
	if (check == 0)
	{
		cout << "No Orders Made\n";
		return false;
	}
	else
	{
		return true;
	}
}


