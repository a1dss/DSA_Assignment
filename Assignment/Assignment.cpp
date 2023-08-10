// Assignment (1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Customer.h"
#include "Admin.h"
#include "FoodList.h"
#include "adminList.h"
#include "customerList.h"
using namespace std;


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
        << "[2] Filter By Categories\n"
        << "[3] Filter By Restaurants\n"
        << "[4] Filter By Price\n"
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
    FoodList FoodList;
    customerList CustList;
    adminList AdminList;
    Admin admin1 = Admin("Admin1", "ThisIsAGoodPassword");
    Admin admin2 = Admin("Admin2", "ThisIsAGreatPassword");
    Admin admin3 = Admin("Admin3", "ThisIsAPassword");
    AdminList.add(admin1);
    AdminList.add(admin2);
    AdminList.add(admin3);
    FoodList.InitList();
    FoodList.DefaultFood();
    
    while (true) {
        string name;
        string pword;
        bool islogin = false;
        bool isadmin = true;
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
                
                cout << "\nUsername: ";
                cin >> name;
                cout << "Password: ";
                cin >> pword;
                islogin = AdminList.Login(name, pword);
                if (!islogin) {
                    islogin = CustList.Login(name, pword);
                    isadmin = false;
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
            Customer newCust =  Customer(newName, newPword);
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
            int option;
            AdminPanel();
            cin >> option;
            
            if (option == 1) { //See Order Details

            }

            else if (option == 2) { //Add Food Item
                string newFName;
                double newFCost;
                string newFCat;
                cout << "Enter New Food Name: ";
                cin.ignore();
                getline(cin, newFName);
                cout << "Enter New Food Cost: ";
                cin >> newFCost;
                cout << "Enter New Food Category: ";
                cin >> newFCat;
                int newFId = FoodList.ReturnCatNum(newFCat);
                FoodList.Add(newFName, newFCost, newFId);
            }

            else if (option == 3) { //See All Food Item
                FoodList.PrintAll();
            }

            else if (option == 4) { // Update Order Status

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
            string choice = UserPanel();
            if (choice == "0")
            {
                islogin = false;
            }
            else if (choice == "1")
            {
                bool ordering = true;
                while (ordering)
                {
                    string orderchoice = OrderPanel();
                    if (orderchoice == "0")
                    {
                        ordering = false;
                    }
                    else if (orderchoice == "1")
                    {

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
                            else if (option == "1")
                            {
                                FoodList.PrintAll();
                            }
                            else if (option == "2")
                            {
                                FoodList.ResetFilter();
                                bool filtering = true;
                                while (filtering)
                                {
                                    FoodList.ShowCata();
                                    cout << "Input catagory number: ";
                                    int catanum;
                                    cin >> catanum;
                                    FoodList.AddFilter(catanum);
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
                                    FoodList.GetFilters();

                                }
                                FoodList.PrintByCata();
                            }
                        }
                    }
                }

            }
            else if (choice == "2")
            {


            }
            else
            {
                cout << choice << endl;
            }


        }
    }

}