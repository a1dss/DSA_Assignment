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

int UserList::hash(Username name) {
	return name.length();
}

bool UserList::add(Username name,Password pword, bool isAdmin) {
	int index = hash(name);

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

void UserList::remove(Username name) {
	int index = hash(name);

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

Username UserList::get(Username name) {

}

bool UserList::isEmpty() {

}

int UserList::getLength() {

}

void UserList::print() {

}
