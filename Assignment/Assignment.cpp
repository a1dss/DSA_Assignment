// Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "FoodList.h"
#include "OrderList.h"
#include "UserList.h"
using namespace std;

int AdminPanel() 
{
    cout << "Welcome\n"
        << "[1] See Orders\n"
        << "[2] Add food item\n"
        << "[3] See all food item\n"
        << "[0] Logout\n"
        << "Please Choose an Option: ";
    int option;
    cin >> option;
    return option;
}

int UserPanel()
{
    cout << "Welcome\n"
        << "[1] Make Orders\n"
        << "[2] Browse food item\n"
        << "[0] Logout\n"
        << "Please Choose an Option: ";
    int option;
    cin >> option;
    return option;
}



int main()
{
    // Init
    FoodList Food;
    Food.InitList();
    UserList userList;
    bool welcomeFlag = true;

    while (welcomeFlag) {
        cout << "Welcome\n"
            << "[1] Log in to Existing Account\n"
            << "[2] Register New Account\n"
            << "[0] Exit\n"
            << "Please Choose an Option: ";
        int option;
        cin >> option;

        if (option == 1) {
            string name;
            string pword;
            welcomeFlag = false;
            cout << "Please Enter the Following:\n";
            while (true) {

                cout << "\nUsername: ";
                cin >> name;
                cout << "Password: ";
                cin >> pword;

                if (userList.Login(name, pword)) {
                    cout << "Login Successful";
                    break;
                }
                else {
                    cout << "Login Failed\n"
                         << "PLease try again";
                }
            }

        }
        else if (option == 2) {
            welcomeFlag = false;
            string newName;
            string newPword;
            cout << "Enter Username";

        }
        //Testing
        else if (option == 3) {
            while (true)
            {
                int choice = AdminPanel();
                if (choice == 2)
                {
                    cout << "Food name: ";
                    string food;
                    cin >> food;
                    Food.ShowCata();
                    int cata;
                    cin >> cata;
                    Food.Add(food, 19, cata);
                }
                else if (choice == 3)
                {
                    Food.PrintAll();
                }
            }

        }
        else if (option == 0) {
            return 0;
        }
        else {
            cout << "Invalid Input";
        }
    }
}




userlist.get()