#pragma once
#include <iostream>
#include <string>
#include <format>
#include "User.h"

typedef int Points;
typedef string Rank;

const int DEFAULT_POINTS = 0;
const string DEFAULT_RANK = "Bronze";

using namespace std;
class Customer : public User
{
private:
	Points points;
	Rank rank;
public:
	Customer();
	Customer(Username, Password,Points,Rank);
	Points getPoints();
	Rank getRank();
	void DisplayInfo();
	void UpdateRank();
	void AddPoints(Points amountAdded);
	double UsePoints(double cost);
	
};

