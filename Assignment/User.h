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