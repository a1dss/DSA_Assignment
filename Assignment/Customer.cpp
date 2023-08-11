#include "Customer.h"

Customer::Customer() {}
Customer::Customer(Username u, Password p,Points ps, Rank r) : User(u, p)
{
	points = ps;
	rank = r;
}

void Customer::DisplayInfo() {
	cout << "Username: " << getUsername() << endl;
	cout << "Points: " << points << endl;
	cout << "Rank: " << rank << endl;
}

void Customer::UpdateRank()
{
    if (points >= 100) {
        rank = "Silver";
    }
    else if (points >= 200) {
        rank = "Gold";
    }
    else if (points >= 300) {
        rank = "Platinum";
    }
}
void Customer::AddPoints(Points amountAdded)
{
    points += amountAdded;
    UpdateRank(); 
}

bool Customer::UsePoints(Points amount)
{
    if (points >= amount) {
        points -= amount;
        return true;
    }   
    else {
        cout << "Insufficient points." << endl;
        return false; 
    }
}