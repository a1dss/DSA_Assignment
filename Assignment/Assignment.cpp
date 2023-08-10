// Assignment (1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Customer.h"
#include "Admin.h"
#include "FoodList.h"
#include "OrderQueue.h"

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
    FoodList foodList;
    foodList.InitList();
    OrderQueue orderqueue;
    foodList.DefaultFood();
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
                OrderItems items;
                while (ordering)
                {
                    cout << items.IsEmpty();
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
                            else if (option == "1")
                            {
                                foodList.PrintAll();
                            }
                            else if (option == "2")
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
                        }
                    }
                    else if (orderchoice == "3")
                    {
                        if (items.IsEmpty())
                        {
                            continue;
                        }
                        else
                        {
                            items.PrintAll(foodList);
                            cout << "Confirm order [Y/N]:";
                            string confirm;
                            cin >> confirm;
                            if (confirm == "Y")
                            {
                                orderqueue.Enqueue(name, items);
                                cout << "Order successful";
                                ordering = false;

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