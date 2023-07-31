#pragma once
#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;
typedef string Username;
typedef string Password;

class UserList
{
private:
	struct User
	{
		Username name;
		Password pword;
		bool isAdmin;
		User* next;
	};

	User* list[MAX_SIZE];
	int size;

	

public:
	// constructor
	UserList();

	// destructor
	~UserList();

	// hash
	int hash(Username user,bool isAdmin);

	bool add(Username user, Password pword,bool isAdmin);

	void remove(Username user, bool isAdmin);

	Username get(Username);

	bool isEmpty();

	int getLength();

	void print();

	bool Login(Username name, Password pword);
};