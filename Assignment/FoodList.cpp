#include "FoodList.h"

void FoodList::InitList()
{
	size = 0;
}


void FoodList::Add(string name, double cost, int cataindex)
{
	bool success = size < MAX_SIZEf;
	FoodItem item;
	item.name = name;
	item.cost = cost;
	item.catagory = CataList[cataindex];
	item.id = size + 1;
	if (success == true)
	{
		FoodArr[size] = item;
		size++;
	}

}

void FoodList::PrintAll()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Food: " << FoodArr[i].name << endl;
	}

}

void FoodList::ShowCata()
{
	cout << "Catagories: ";
	for (int i = 0; i < 8; i++)
	{
		cout << "(" << i+1 << ") " << CataList[i] << "  ";
	}
	cout << endl;
}
