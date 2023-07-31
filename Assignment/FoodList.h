#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef string Name;
typedef int Cost;
typedef string Category;

class Food
{


private:
	struct FoodItem
	{
		Name name;
		Cost cost;
		Category catagory;
	};

	Food* FoodArr[1000];
	int size;

public:
	//Initial List creation(Food)
	void InitList();

	//Add food to list
	bool Add(string name, int cost, string catagory);

	//Remove food from list
	bool Remove(string name);

	//List all food option and prices
	void PrintAll();

	//Print food options filtered by catagory
	void PrintByCata(string catagory);

	//Search for food item and return the index
	int Search(string name);


};

