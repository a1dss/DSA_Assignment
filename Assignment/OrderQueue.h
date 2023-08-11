#pragma once
#include <iostream>
#include <string>
#include "OrderItems.h"

using namespace std;
typedef string Orderer;
typedef int OrderID;
typedef string Status;
typedef OrderItems ItemList;

class OrderQueue
{
	struct Order
	{
		Orderer user;
		Status status;
		ItemList itemList;
		Order* next;

	};

	

	Order* firstNode;
	Order* lastNode;

public:

	//constructor
	OrderQueue();

	//deconstructor
	//~OrderQueue();

	//Check if queue is empty
	bool isEmpty();

	//Queue order
	//Prequisite: Item List must not be empty
	bool enqueue(string cust, OrderItems items);

	//Remove first item of queue
	bool dequeue();

	//Update status
	void updateStatus(int pos);

	//Get status of order
	string getStatus(int pos);

	//List all current orders
	void listOrders(FoodList foodList);

	//List all orders of current user
	void listOrders(string user);

	//Change status to cancel if status is preparing and is the surrent user's order
	bool updateStatus(string user, int pos);

	//Get Total of current order
	double calcTotal();

};

