#pragma once
#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;
const int CUST_SIZE = 100;

class customerList
{
private:

	//Dictionary Implementation
	struct CustNode {
		Customer cust;
		CustNode* next;
	};

	CustNode* CustList[CUST_SIZE];
	int custSize;

public:

	//Constructor
	customerList();

	//Deconstructor
	~customerList();
	
	//Hash fucntion for customer
	int hash(int len);
	
	//Add customer to Dictionary
	// Prerequsite: Name must not exist in the dictionary
	// returns true if Customer added successfully
	bool add(Customer cust);
	
	//Add customer to Dictionary
	// Prerequsite: dictionary is not empty
	// returns true if Customer added successfully
	void remove(Customer cust);
	
	// Get customer object using username
	// returns customer object if username matches
	Customer get(Username username);
	
	//Check if list is empty
	bool isEmpty();
	
	//Returns the number of customers in dictionary
	int getLength();
	
	//Print all customer details in Dictionary 
	void print();
	
	// Login function for user
	// return true if username and password match the corressponding Customer object in dictionary
	bool Login(Username username, Password pword);

	
	void update(Customer customer);
};


