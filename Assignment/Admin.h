#pragma once
#include <iostream>
#include <string>
#include "User.h"
using namespace std;

class Admin :public User
{
private:

public:
	Admin();
	Admin(Username, Password);

};
