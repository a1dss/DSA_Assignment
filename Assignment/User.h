// Team Member 1: Aidan Toh Qun Kai, S10243503 
// Team Member 2: Goh Bing Lo, S10242470

#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef string Username;
typedef string Password;


//Parent class to User and Admin
class User
{
private:
	Username username;
	Password pword;


public:
	User();

	User(Username, Password);

	void setUsername(Username);
	Username getUsername();

	void setPassword(Password);
	Password getPassword();

	void print();
};