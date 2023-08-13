#pragma once
#include <iostream>
#include <string>
#include "Admin.h"
using namespace std;

const int ADMIN_SIZE = 10;

class adminList
{
private:
	//Dictionary Implementation
	struct AdminNode {
		Admin admin;
		AdminNode* next;
	};

	AdminNode* AdminList[ADMIN_SIZE];
	int adminSize;

public:
	//Constrcutor
	adminList();

	//Deconstructor
	~adminList();


	// Hash function fro admin
	// Return index for dictionary access
	int hash(int len);

	// Add Admin to Dictionary
	// Prerequisite: Admin must not exist in the dictionary
	bool add(Admin admin);

	// Remove Admin from Dictionary
	// Prerequsite: dictionary is not empty
	void remove(Admin admin);

	//Fuction to get admin Object from username
	// Returns Admin object if username attribute matches
	Admin get(Username username);

	//Check if dictionary is empty
	bool isEmpty();

	// Get total number of admins
	int getLength();

	//Print all admin information
	void print();

	// Fuction to compare params to admin object in dictionary
	// Returns true object if bath params match the Admin object
	bool Login(Username name, Password pword);

};

