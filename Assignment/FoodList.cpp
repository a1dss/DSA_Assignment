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
	item.catagory = cataindex - 1;
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
		cout << format("ID:{0:<5}Name:{1:15}Price:{2:.2f}", FoodArr[i].id, FoodArr[i].name, FoodArr[i].cost) << endl;

	}

}


void FoodList::ShowCata()
{
	cout << "Catagories: ";
	for (int i = 0; i < 8; i++)
	{
		cout << "(" << i + 1 << ") " << CataList[i] << "  ";
	}
	cout << endl;

}

void FoodList::ResetFilter()
{
	for (int i = 0; i < cate_count; i++)
	{
		Filters[i] = false;
	}
}
void FoodList::AddFilter(int index)
{
	Filters[index - 1] = true;
}


void FoodList::GetFilters()
{
	cout << "Filters: ";
	for (int i = 0; i < cate_count; i++)
	{
		if (Filters[i])
		{
			cout << CataList[i] << ",   ";
		}

	}
	cout << endl;
}


void FoodList::PrintByCata()
{
	for (int i = 0; i < size; i++)
	{

		if (Filters[FoodArr[i].catagory])
		{
			cout << format("ID:{0:<5}Name:{1:15}Price:{2:.2f}", FoodArr[i].id, FoodArr[i].name, FoodArr[i].cost) << endl;
		}

	}

}

void FoodList::DefaultFood()
{
	Add("Nasi Lemak", 19, 3);
	Add("Milk Tea", 1, 8);
	Add("Pad Thai", 12, 7);
	Add("Bimbap", 22, 6);
	Add("Katsudon", 1.5, 5);
	Add("Roti Prata", 6.9, 4);
	Add("Kimchi Noodle", 14, 6);
	Add("Hamburger", 100.99, 2);
	Add("Beef Rendang", 52.49, 3);
	Add("Char Siew Bao", 52.49, 1);
	Add("Fried Chicken", 1.9, 2);
	Add("Watermelon", 8.88, 8);
}

int FoodList::ReturnCatNum(string category) {


	int count = 0;
	while (CataList[count] != category) {
		count += 1;
		if (count >cate_count) 
		{
			return -1;
		}
	}
	return count + 1;
	
}

FoodList::FoodItem FoodList::GetFoodItem(int index) {
	return FoodArr[index];
}

void FoodList::InsertionSort() {
	for (int i = 1; i < size; i++) {
		FoodItem data = FoodArr[i];

		int last = i;
		while ((last > 0) && (FoodArr[last - 1].cost > data.cost)) {
			FoodArr[last] = FoodArr[last - 1];
			last--;
		}
		FoodArr[last] = data;
	}
}

void FoodList::InsertionSortReverse() {
	for (int i = 1; i < size; i++) {
		FoodItem data = FoodArr[i];

		int last = i;
		while ((last > 0) && (FoodArr[last - 1].cost < data.cost)) {
			FoodArr[last] = FoodArr[last - 1];
			last--;
		}
		FoodArr[last] = data;
	}
}