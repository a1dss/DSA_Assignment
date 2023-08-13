// Team Member 1: Aidan Toh Qun Kai, S10243503 
// Team Member 2: Goh Bing Lo, S10242470

#include "User.h"
#include <iostream>
#include <string>

using namespace std;

User::User() {};

User::User(Username u, Password p) :username(u), pword(p) {};

void User::setUsername(Username uname) { username = uname; }
Username User::getUsername() { return username; }

void User::setPassword(Password pass) { pword = pass; }
Username User::getPassword() { return pword; }

void User::print() {
	cout << "Hello World";
}