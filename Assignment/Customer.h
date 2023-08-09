#pragma once
#include <iostream>
#include <string>
#include "User.h"
using namespace std;
class Customer : public User
{
private:

public:
	Customer();
	Customer(Username, Password);
};

