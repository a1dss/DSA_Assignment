// Team Member 1: Aidan Toh Qun Kai, S10243503 
// Team Member 2: Goh Bing Lo, S10242470

#include "customerList.h"


// functions similar to those of adminList

customerList::customerList() {
	for (int i = 0; i < CUST_SIZE;i++) {
		CustList[i] = nullptr;
	}
	custSize = 0;
}

customerList:: ~customerList() {
	for (int i = 0; i < CUST_SIZE;i++) {
		delete CustList[i];
		CustList[i] = nullptr;
	}
	custSize = 0;
}

int customerList::hash(string username) {
	const int prime = 31;  // A prime number for better distribution
	int len = username.length();

	int hashValue = 0;
	for (char c : username) {
		hashValue = hashValue * prime + c;
	}

	return hashValue % CUST_SIZE;
}

bool customerList::add(Customer cust) {
	int index = hash(cust.getUsername());

	CustNode* newCust = new CustNode;
	newCust->cust = cust;
	newCust->next = NULL;

	if (CustList[index] == nullptr) {
		CustList[index] = newCust;
	}
	else {
		CustNode* current = CustList[index];

		if (current->cust.getUsername() == cust.getUsername()) {
			delete newCust;
			cout << "Existing Username" << endl;
			return false;
		}
		while (current->next != nullptr) {
			if (current->cust.getUsername() == cust.getUsername()) {
				delete newCust;
				cout << "Existing Username" << endl;
				return false;
			}
			current = current->next;
		}
		current->next = newCust;
	}
	custSize++;
}

void customerList::remove(Customer cust) {
	int index = hash(cust.getUsername());
	CustNode* prev = CustList[index];
	if (prev == nullptr) {
		cout << "Item not found" << endl;
		return;
	}
	CustNode* current = prev->next;

	if (prev->cust.getUsername() == cust.getUsername()) {
		CustList[index] = current;
		delete prev;
		cout << "Item deleted" << endl;
		return;
	}
	while (current != NULL && current->cust.getUsername() != cust.getUsername()) {
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
	custSize--;
}

Customer customerList::get(Username username) {
	int index = hash(username);
	CustNode* current = CustList[index];

	while (current != nullptr && current->cust.getUsername() != username) {
		current = current->next;
	}

	if (current == NULL) {
		
		return Customer();
	}

	return current->cust;

}

bool customerList::isEmpty() {
	if (custSize == 0) {
		return true;
	}
	return false;
}

int customerList::getLength() {
	return custSize;
}

void customerList::print() {
	for (int i = 0; i < CUST_SIZE; i++) {
		CustNode* current = CustList[i];

		while (current != nullptr) {
			cout << "Key: " << current->cust.getUsername() << endl;
			current = current->next;
		}
	}
}

bool customerList::Login(Username username, Password pwrod) {
	int index = hash(username);
	
	CustNode* current = CustList[index];
	while (current != nullptr) {
		if (current->cust.getUsername() == username && current->cust.getPassword() == pwrod) {
			return true;
		}
		current = current->next;
	}
	cout << "Invalid Username or Password" << endl;
	return false;
}

void customerList::update(Customer customer)
{
	int index = hash(customer.getUsername());

	CustNode* current = CustList[index];
	while (current != nullptr) {
		if (current->cust.getUsername() == customer.getUsername())
		{
			current->cust = customer;
		}
		current = current->next;
	}
}