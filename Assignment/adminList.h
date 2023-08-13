#pragma once
#include <iostream>
#include <string>
#include "Admin.h"
using namespace std;

const int ADMIN_SIZE = 10;

class adminList
{
private:
	struct AdminNode {
		Admin admin;

		AdminNode* next;
	};

	AdminNode* AdminList[ADMIN_SIZE];
	int adminSize;

public:
	adminList();

	~adminList();

	int hash(string username);

	bool add(Admin admin);

	void remove(Admin admin);

	Admin get(Username username);

	bool isEmpty();

	int getLength();

	void print();

	bool Login(Username name, Password pword);

};

