#pragma once
#include <iostream>
#include <string>
#include "OrderItems.h"

using namespace std;
typedef string User;
typedef int OrderID;
typedef string Status;
typedef OrderItems ItemList;

class OrderQueue
{
	struct Order
	{
		User user;
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
	~OrderQueue();

	//Check if queue is empty
	bool isEmpty();

	//Queue order
	//Prequisite: Item List must not be empty
	bool enqueue(string cust, OrderItems items);

	//Remove first item of queue
	void dequeue();

	//Update status
	void updateStatus(int pos);

	//Get status of order
	string getStatus(int pos);

	//List all current orders
	void listOrders();

	//List all orders of current user
	void listOrders(string user);

	//Remove a order only if status is preparing
	bool remove(string user, int pos);

	//Get Total of current order
	double calcTotal();

};

