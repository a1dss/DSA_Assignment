// Team Member 1: Aidan Toh Qun Kai, S10243503 
// Team Member 2: Goh Bing Lo, S10242470

#pragma once
#include <iostream>
#include <string>
#include <format>
#include "User.h"

typedef int Points;
typedef string Rank;



using namespace std;


class Customer : public User
{
private:
	Points points;
	Rank rank;
public:
	Customer();
	Customer(Username, Password,Points,Rank);

	//Get point attribute of Customer obj
	Points getPoints();

	//Get rank attribute of Customer obj
	Rank getRank();

	//Display all attribute of Customer obj
	void DisplayInfo();

	// Function to update rank attribute based of current point attribute
	void UpdateRank();

	// Function to update point and rank attribute based of the amount inputted into function
	void AddPoints(double amountAdded);

	// Function to update point attribute from the params, deducts cost based on number of points
	// Returns the deducted cost
	double UsePoints(double cost);
	
};

