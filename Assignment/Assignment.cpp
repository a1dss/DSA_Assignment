// Assignment (1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <format>
#include <string>
#include "Customer.h"
#include "Admin.h"
#include "FoodList.h"
#include "adminList.h"
#include "customerList.h"
#include "OrderItems.h"
#include "OrderQueue.h"
using namespace std;



bool isSubstring(const string& mainString, const string& substring) {
    for (size_t i = 0; i <= mainString.length() - substring.length(); i++) {
        size_t j;
        for (j = 0; j < substring.length(); j++) {
            if (mainString[i + j] != substring[j]) {
                break;
            }
        }
        if (j == substring.length()) {
            return true; // Substring found
        }
    }
    return false; // Substring not found
}

void AdminPanel()
{
    cout << "Welcome\n"
        << "[1] See Order Details\n"
        << "[2] Add food item\n"
        << "[3] See all food item\n"
        << "[4] Update Order status\n"
        << "[0] Logout\n"
        << "Please Choose an Option: ";
   
}



string FoodViewPanel()
{

    cout << "[1] Show all food\n"
        << "[2] Sort By Price (Min - Max)\n"
        << "[3] Sort by Price (Max - Min)\n"
        << "[4] Filter By Category\n"
        << "[5] Search by substring\n"
        << "[0] Return\n"
        << "Please Choose an Option: ";

    string option;
    cin >> option;
    return option;


}

string UserPanel()
{
    cout << "Welcome\n"
        << "[1] Make Order\n"
        << "[2] View Order\n"
        << "[3] Membership\n"
        << "[0] Logout\n"
        << "Please Choose an Option: ";

    string option;
    cin >> option;
    return option;
}

string OrderPanel()
{
    cout << "Welcome\n"
        << "[1] Add Item\n"
        << "[2] Browse items\n"
        << "[3] Confirm\n"
        << "[0] Cancel\n"
        << "Please Choose an Option: ";

    string option;
    cin >> option;
    return option;
}


int main()
{
    FoodList foodList;
    customerList CustList;
    adminList AdminList;
    OrderQueue orderqueue;
    Admin admin1 = Admin("Admin1", "ThisIsAGoodPassword");
    Admin admin2 = Admin("Admin2", "ThisIsAGreatPassword");
    Admin admin3 = Admin("Admin3", "ThisIsAPassword");
    AdminList.add(admin1);
    AdminList.add(admin2);
    AdminList.add(admin3);
    foodList.InitList();
    foodList.DefaultFood();
    
    while (true) {
        string name;
        string pword;
        bool islogin = false;
        bool isadmin = true;
        Admin currAdmin;
        Customer currCust;
        cout << "Welcome\n"
            << "[1] Log in to Existing Account\n"
            << "[2] Register New Account\n"
            << "[0] Exit\n"
            << "Please Choose an Option: ";
        string option;
        cin >> option;
        
        if (option == "1") {
            
            cout << "Please Enter the Following:\n";
            while (true) {
                islogin = false;
                isadmin = true;

                cout << "\nUsername: ";
                cin >> name;
                cout << "Password: ";
                cin >> pword;
                islogin = AdminList.Login(name, pword);
                currAdmin = AdminList.get(name);
                
                if (!islogin) {
                    islogin = CustList.Login(name, pword);
                    isadmin = false;
                    currCust = CustList.get(name);
                    
                    
                }

                if (islogin) {
                    break;
                }
            }

        }
        else if (option == "2") { //For register, assume only Customers can register via the page. 
            string newName;
            string newPword;
            cout << "Enter Username: ";
            cin >> newName;
            cout << "Enter Password: ";
            cin >> newPword;
            Customer newCust =  Customer(newName, newPword,DEFAULT_POINTS,DEFAULT_RANK);
            CustList.add(newCust);


        }
        else if (option == "0") {
            cout << "Goodbye";
            return 0;
        }
        else {
            cout << "Invalid Input\n";
        }
        while (islogin && isadmin) {
            orderqueue.dequeue();
            int option;
            AdminPanel();
            cin >> option;
            
            if (option == 1) { //See Order Details
                orderqueue.listOrders(foodList);
            }

            else if (option == 2) { //Add Food Item
                string newFName;
                double newFCost;
                string newFCat;
                cout << "Enter New Food Name: ";
                cin.ignore();             //Reads entire line, including spaces
                getline(cin, newFName);
                cout << "Enter New Food Cost: ";
                cin >> newFCost;
                cout << "Enter New Food Category: ";
                cin >> newFCat;
                int newFId = foodList.ReturnCatNum(newFCat);
                foodList.Add(newFName, newFCost, newFId);
            }

            else if (option == 3) { //See All Food Item
                foodList.PrintAll();
            }

            else if (option == 4) { // Update Order Status
                cout << "Change status of first order to completed [Y/N]:";
                string confirm;
                cin >> confirm;
                if (confirm == "Y")
                {
                    orderqueue.dequeue();

                }
                else if (confirm == "N")
                {
                    continue;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }

            else if (option == 0) { // Log out
                islogin = false;
                isadmin = true;
            }
            else {
                cout << "Invalid Input" << endl;
            }
            

        }
        while (islogin && !isadmin)
        {
            orderqueue.dequeue();
            string choice = UserPanel();
            if (choice == "0")
            {
                islogin = false;
            }
            else if (choice == "1")
            {
                bool ordering = true;
                OrderItems items;
                while (ordering)
                {

                    string orderchoice = OrderPanel();
                    if (orderchoice == "0")
                    {
                        ordering = false;
                    }
                    else if (orderchoice == "1")
                    {
                        cout << "Input Food ID:";
                        int foodno;
                        cin >> foodno;
                        cout << "Input Quantity:";
                        int qty;
                        cin >> qty;

                        items.AddtoList(foodno, qty, foodList);
                        items.PrintAll(foodList);

                    }
                    else if (orderchoice == "2")
                    {
                        while (true)
                        {
                            cout << endl;
                            string option = FoodViewPanel();
                            if (option == "0")
                            {
                                break;
                            }
                            else if (option == "1") //Show all food 
                            {
                                foodList.PrintAll();
                            }
                            else if (option == "2") { //Show all sorted by price (Min-Max)
                                FoodList sortedFoodList;
                                sortedFoodList.InitList();
                                for (int i = 0; i < foodList.size;i++) {
                                    string foodName = foodList.GetFoodItem(i).name;
                                    double foodCost = foodList.GetFoodItem(i).cost;
                                    int foodCataIndex = foodList.GetFoodItem(i).catagory;
                                    sortedFoodList.Add(foodName,foodCost,foodCataIndex) ;
                                }
                                sortedFoodList.InsertionSort();
                                sortedFoodList.PrintAll();
                            }
                            else if (option == "3") { //Show all sorted by price (Max-Min)
                                FoodList sortedFoodList;
                                sortedFoodList.InitList();
                                for (int i = 0; i < foodList.size;i++) {
                                    string foodName = foodList.GetFoodItem(i).name;
                                    double foodCost = foodList.GetFoodItem(i).cost;
                                    int foodCataIndex = foodList.GetFoodItem(i).catagory;
                                    sortedFoodList.Add(foodName, foodCost, foodCataIndex);
                                }
                                sortedFoodList.InsertionSortReverse();
                                sortedFoodList.PrintAll();
                            }
                            else if (option == "4") //Filter by Catagory
                            {
                                foodList.ResetFilter();
                                bool filtering = true;
                                while (filtering)
                                {
                                    foodList.ShowCata();
                                    cout << "Input catagory number: ";
                                    int catanum;
                                    cin >> catanum;
                                    foodList.AddFilter(catanum);
                                    while (true)
                                    {
                                        cout << "Add more filters [Y/N]: ";
                                        string exit;
                                        cin >> exit;
                                        if (exit == "N")
                                        {
                                            filtering = false;
                                            break;
                                        }
                                        else if (exit == "Y")
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Invalid input";
                                        }
                                    }
                                    foodList.GetFilters();

                                }
                                foodList.PrintByCata();
                            }
                            
                            else if (option == "5") {
                                string substring;
                                cout << "Enter Substring: ";
                                cin.ignore();
                                getline(cin,substring);
                                bool contains = false;
                                for (int i = 0; i < foodList.size;i++) {
                                    string foodName = foodList.GetFoodItem(i).name;
                                    double foodCost = foodList.GetFoodItem(i).cost;
                                    int foodId = foodList.GetFoodItem(i).id;
                                    if (isSubstring(foodName, substring)) {
                                        cout << format("ID:{0:<5}Name:{1:15}Price:{2:.2f}", foodId,foodName,foodCost) << endl;
                                        contains = true;
                                    }
                                }
                                if (!contains) {
                                    cout << "Substring not found!";
                                }
                            }
                        }
                    }
                    else if (orderchoice == "3")
                    {
                        if (items.IsEmpty())
                        {
                            cout << "Order is empty" << endl;
                            continue;
                        }
                        else
                        {
                            items.PrintAll(foodList);
                            double cost = items.CalculateTotal(foodList);
                            cout << "Confirm order and make payment [Y/N]:";
                            string confirm;
                            cin >> confirm;
                            if (confirm == "Y")
                            {
                                cout << format("Total Cost: ${:.2f}", cost) << endl;
                                cout << "Would you like to use your points(Current Points: " << currCust.getPoints() << ") ? [Y/N] ";
                                cin >> confirm;
                                if (confirm == "Y") {
                                    cost = currCust.UsePoints(cost);
                                }
                                else {
                                    currCust.AddPoints(cost);
                                }

                                
                                orderqueue.enqueue(name, items);
                                cout << "Order successful\n";
                                cout << format("Payment of ${:.2f} made\n", cost) << endl;
                                ordering = false;

                            }
                            else if (confirm == "N")
                            {
                                currCust.AddPoints(cost);
                                continue;
                            }
                            else
                            {
                                cout << "Invalid Input" << endl;
                            }
                        }

                    }
                    else
                    {
                        cout << "Invalid Input" << endl;
                    }



                }

            }
            else if (choice == "2")
            {
     
                char cancel;
                bool hasorders;
                hasorders = orderqueue.listOrders(name, foodList);
                if (hasorders)
                { 
                    cout << "Cancel Order[Y/N]: ";
                    cin >> cancel;
                    if (towupper(cancel) == 'Y')
                    {
                        cout << "Input Order Number: ";
                        int ornum;
                        cin >> ornum;
                        orderqueue.cancelOrder(name, ornum);
                    }
                    else if (towupper(cancel) == 'N')
                    {
                        continue;
                    }
                    else
                    {
                        cout << "Invalid input\n";
                    }
                }
                else
                {
                    
                }



            }
            else if (choice == "3") {
                cout << "Current Rank: " << currCust.getRank() << "\tCurrent Points: " << currCust.getPoints() << endl;
            }
           
            else
            {
                cout << "Invalid Input" << endl;
            }


        }
    }

}