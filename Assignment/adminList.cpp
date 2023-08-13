#include "adminList.h"

adminList::adminList() {
	for (int i = 0;i < ADMIN_SIZE;i++) {
		AdminList[i] = nullptr;
	}
	adminSize = 0;
}

adminList::~adminList() {
	for (int i = 0; i < ADMIN_SIZE; i++) {
		delete AdminList[i];
		AdminList[i] = nullptr;
	}
	adminSize = 0;
}


int adminList::hash(string username) {
	const int prime = 31;  // A prime number for better distribution
	int len = username.length();

	int hashValue = 0;
	for (char c : username) {
		hashValue = hashValue * prime + c;
	}

	return hashValue % ADMIN_SIZE;
}

bool adminList::add(Admin admin) {
	int index = hash(admin.getUsername());

	AdminNode* newAdmin = new AdminNode;
	newAdmin->admin = admin;
	newAdmin->next = NULL;

	if (AdminList[index] == nullptr) {
		AdminList[index] = newAdmin;
	}
	else {
		AdminNode* current = AdminList[index];

		if (current->admin.getUsername() == admin.getUsername()) {
			delete newAdmin;
			cout << "Existing Username." << endl;
			return false;
		}

		while (current->next != nullptr) {
			if (current->admin.getUsername() == admin.getUsername()) {
				delete newAdmin;
				cout << "Existing Username" << endl;
				return false;
			}
			current = current->next;
		}
		current->next = newAdmin;
	}
	adminSize++;
}

void adminList::remove(Admin admin) {
	int index = hash(admin.getUsername());
	AdminNode* prev = AdminList[index];
	if (prev == nullptr) {
		cout << "Item not found" << endl;
		return;
	}
	AdminNode* current = prev->next;

	if (prev->admin.getUsername() == admin.getUsername()) {
		AdminList[index] = current;
		delete prev;
		cout << "Item deleted" << endl;
		return;
	}
	while (current != NULL && current->admin.getUsername() != admin.getUsername()) {
		prev = current;
		current = current->next;
	}
	if (current == NULL) {
		cout << "Item not found" << endl;
		return;
	}
	prev->next = current->next;
	delete current;
	cout << "Item deleted" << endl;
	adminSize--;
}

Admin adminList::get(Username username) {
	int index = hash(username);

	AdminNode* current = AdminList[index];

	while (current != nullptr && current->admin.getUsername() != username) {
		current = current->next;
	}

	if (current == NULL) {
		return Admin();
	}
	
	return current->admin;
}

bool adminList::isEmpty() {
	if (adminSize == 0) {
		return true;
	}
	return false;
}

int adminList::getLength() {
	return adminSize;
}
void adminList::print() {
	for (int i = 0; i < ADMIN_SIZE; i++) {
		AdminNode* current = AdminList[i];


		while (current != nullptr) {
			cout << "Key: " << current->admin.getUsername() << endl;
			current = current->next;
		}
	}
}
bool adminList::Login(Username username, Password pwrod) {
	int index = hash(username);
	
	AdminNode* current = AdminList[index];
	while (current != nullptr) {
		if (current->admin.getUsername() == username && current->admin.getPassword() == pwrod) {
			return true;
		}
		current = current->next;
	}
	
	
	return false;
}

