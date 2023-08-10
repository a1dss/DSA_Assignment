// Assignment (1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Customer.h"
#include "Admin.h"
#include "FoodList.h"
using namespace std;


int AdminPanel()
{
    cout << "Welcome\n"
        << "[1] See Order Details\n"
        << "[2] Add food item\n"
        << "[3] See all food item\n"
        << "[5] Update Order status\n"
        << "[0] Logout\n"
        << "Please Choose an Option: ";
    try
    {
        int option;
        cin >> option;
        throw option;
    }
    catch (int x)
    {
        return x;
    }
    catch (...)
    {
        return -1;
    }

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
    FoodList.InitList();
    FoodList.DefaultFood();
    string name;
    string pword;
    bool islogin = false;
    while (true) {
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
                islogin = true;
                break;
                //if (userList.Login(name, pword)) {
                //    cout << "Login Successful";
                //    break;
                //}
                //else {
                //    cout << "Login Failed\n"
                //        << "PLease try again";
                //}
            }

        }
        else if (option == "2") {
            string newName;
            string newPword;
            cout << "Enter Username";

        }
        else if (option == "0") {
            cout << "Goodbye";
            return 0;
        }
        else {
            cout << "Invalid Input\n";
        }

        while (islogin)
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