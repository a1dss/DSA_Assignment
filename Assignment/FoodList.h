#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef string Name;
typedef double Cost;
typedef string Category;
typedef int foodID;
int const MAX_SIZEf = 1000;

class FoodList
{


private:
	struct FoodItem
	{
		Name name;
		Cost cost;
		Category catagory;
		foodID id;
	};

	FoodItem FoodArr[MAX_SIZEf];
	int size;
	string CataList[8] = {"Chinese","Western","Malay","Indian","Japanese","Korean","Thai","Others"};

public:
	//Initial List creation(Food)
	void InitList();

	//Add food to list
	void Add(string name, double cost, int catagory);

	//Remove food from list
	bool Remove(int foodid);

	//List all food option and prices
	void PrintAll();

	//Print food options filtered by catagory
	void PrintByCata(string catagory);

	//Search for food item and return the index
	int Search(string name);

	//Show all current categorys
	void ShowCata();
};

