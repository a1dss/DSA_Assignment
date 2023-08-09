#pragma once
#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;
const int MAX_SIZE = 100;

class customerList
{
private:
	struct CustNode {
		Customer cust;
		CustNode* next;
	};

	CustNode* CustList[MAX_SIZE];
	int custSize;

public:
	customerList();

	~customerList();
	
	int hash(int len);
	
	bool add(Customer cust);
	
	void remove(Customer cust);
	
	Customer get(Username username);
	
	bool isEmpty();
	
	int getLength();
	
	void print();
	
	bool Login(Username username, Password pword);
};


