#include "UserList.h"
#include <iostream>
#include <string>

using namespace std;

UserList::UserList() {
	for (int i = 0;i < MAX_SIZE;i++) {
		list[i] = nullptr;
	}
	size = 0;
}

UserList::~UserList() {
	for (int i = 0; i < MAX_SIZE; i++) {
		delete list[i];  
		list[i] = nullptr; 
	}
}

int UserList::hash(Username name,bool isAdmin) {
	if (isAdmin) {
		return name.length() % 3;
		// Ensures Index is either 0,1,2
	}

	int index = name.length() % MAX_SIZE;

	if (index < 3) {
		index += 3;
	}
	return index;
}

bool UserList::add(Username name, Password pword, bool isAdmin) {
	int index = hash(name, isAdmin);

	User* newUser = new User;
	newUser->name = name;
	newUser->pword = pword;
	newUser->isAdmin = isAdmin;
	newUser->next = NULL;

	if (list[index] == nullptr) {
		list[index] = newUser;
	}

	else {
		User* current = list[index];

		if (current->name == name) {
			delete newUser;
			cout << "Existing Username." << endl;
			return false;
		}

		while (current->next != nullptr) {
			if (current->name == name) {
				delete newUser;
				cout << "Existing Username" << endl;
				return false;
			}
			current = current->next;
		}
		current->next = newUser;
	}
	size++;
	return true;

}


void UserList::remove(Username name,bool isAdmin) {
	int index = hash(name,isAdmin);

	User* prev = list[index];
	if (prev == nullptr) {
		cout << "Username not found" << endl;
		return;
	}
	User* current = prev->next;

	if (prev->name == name) {
		list[index] = current;
		delete prev;
		cout << "Account Deleted" << endl;
		return;
	}

	while (current != NULL && current->name != name) {
		prev = current;
		current = current->next;
	}

	if (current == NULL) {
		cout << "Username not Found" << endl;
		return;
	}

	prev->next = current->next;
	delete current;
	cout << "Account Deleted" << endl;
	size--;
}



string UserList::get(Username user) {
	return user;
}

bool UserList::isEmpty() {
	return true;
}

int UserList::getLength() {
	return 0;
}

void UserList::print() {
	for (int i = 0; i < MAX_SIZE; i++) {
		User* current = list[i];


		while (current != nullptr) {
			cout << "Key: " << current->name << "      Item: " << current->pword << endl;
			current = current->next;
		}
	}
}

bool UserList::Login(Username name, Password pword) {
	for (int i = 0; i < MAX_SIZE; i++) {
		User* current = list[i];

		while (current != nullptr) {
			if (current->name == name and current->pword == pword) {
				return true;
			}
		}
	}
	return false;
}
	
