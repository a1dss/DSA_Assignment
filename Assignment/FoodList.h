// Team Member 1: Aidan Toh Qun Kai, S10243503 
// Team Member 2: Goh Bing Lo, S10242470

#pragma once
#include <iostream>
#include <string>
#include <format>
#include <cctype>
using namespace std;

typedef string Name;
typedef double Cost;
typedef int CategoryID;
typedef int foodID;
int const MAX_SIZEf = 100;
int const cate_count = 8;


class FoodList
{


private:
	struct FoodItem
	{
		Name name;
		Cost cost;
		CategoryID catagory;
		foodID id;

	};



	string const CataList[cate_count] = { "Chinese","Western","Malay","Indian","Japanese","Korean","Thai","Others" };
	bool Filters[cate_count] = { false,false,false,false,false,false,false,false };

public:
	//Array Implementation
	int size;
	FoodItem FoodArr[MAX_SIZEf];


	//Initial List creation(Food)
	void InitList();


	//Add food to list
	void Add(string name, double cost, int catagory);

	void Remove(int id);

	//List all food option and prices
	void PrintAll();

	

	//List all food filtered by categories
	void PrintByCata();

	//Reset Filters
	void  ResetFilter();

	//Add filters
	void AddFilter(int index);

	//Print food options filtered by catagory
	void GetFilters();

	//Show all current categorys
	void ShowCata();


	void DefaultFood();

	int ReturnCatNum(string category);
	FoodItem GetFoodItem(int index);

	// Sorting function for list by cost (lowest to highest)
	void InsertionSort();

	// Sorting function for list by cost (highest to lowest)
	void InsertionSortReverse();
	bool Exist(string name);
};