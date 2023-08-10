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
	bool Enqueue(string cust, OrderItems items);

	//Remove first item of queue
	void Dequeue();

	//Update status
	void UpdateStatus(int pos);

	//Get status of order
	string GetStatus(int pos);

	//List all current orders
	void ListOrders();

	//List all orders of current user
	void ListOrders(string user);

	//Remove a order only if status is preparing
	bool Remove(string user, int pos);

	//Get Total of current order
	double CalcTotal();

};

