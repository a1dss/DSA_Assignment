#pragma once
#include <iostream>
#include <string>
#include "Admin.h"
using namespace std;

const int MAX_SIZE = 10;

class adminList
{
private:
	struct AdminNode {
		Admin admin;

		AdminNode* next;
	};

	AdminNode* AdminList[MAX_SIZE];
	int adminSize;

public:
	adminList();

	~adminList();

	int hash(int len);

	bool add(Admin admin);

	void remove(Admin admin);

	Admin get(Username username);

	bool isEmpty();

	int getLength();

	void print();

	bool Login(Username name, Password pword);
};

