// Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "FoodList.h"
#include "OrderList.h"
#include "UserList.h"

using namespace std;
int main()
{
    // Init
    UserList userList;
    bool welcomeFlag = true;
    while (welcomeFlag) {
        cout << "Welcome\n"
            << "[1] Log in to Existing Account\n"
            << "[2] Register New Account\n"
            << "[0] Exit\n"
            << "Please Choose an Option";
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
        }
        else if (option == 0) {
            return 0;
        }
        else {
            cout << "Invalid Input";
        }
    }
}

void printLogin() {
    cout << "Welcome:";
}

