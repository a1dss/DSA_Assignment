#include "Customer.h"

Customer::Customer() {}

Customer::Customer(Username u, Password p,Points ps, Rank r) : User(u, p)
{
	points = ps;
	rank = r;
}

Points Customer::getPoints() {
    return points;
}

Rank Customer::getRank() {
    return rank;
}

void Customer::DisplayInfo() {
	cout << "Username: " << getUsername() << endl;
	cout << "Points: " << points << endl;
	cout << "Rank: " << rank << endl;
}

void Customer::UpdateRank()
{
    if (points >= 300) {
        rank = "Platinum";
    }
    else if (points >= 200) {
        rank = "Gold";
    }
    else if (points >= 100){
        rank = "Silver";
    }

}
void Customer::AddPoints(Points amountSpent)
{
    amountSpent *= 100;  // Convert to cents
    points += amountSpent/10; // Every 10 cents = 1 point
    UpdateRank(); 
    cout << "New Rank: " << rank << endl;
}

bool Customer::UsePoints(int cost)
{
    int discountAmt;
    int finalCost;

    Points pointsWorth = 1; // Default value for points' worth

    if (rank == "Silver") {
        pointsWorth = 2; // Points are worth 2 at Silver rank
    }
    else if (rank == "Gold") {
        pointsWorth = 3; // Points are worth 3 at Gold rank
    }
    else if (rank == "Platinum") {
        pointsWorth = 4; // Points are worth 4 at Platinum rank
    }
    
    if ((points * pointsWorth)/100 >= cost) {
        discountAmt = cost;
        finalCost = 0;
        points -= (cost * 100)/pointsWorth;
    }
    else {
        discountAmt = (points * pointsWorth) / 100;
        finalCost = cost - discountAmt;
        points = 0;
    }
    cout << "Discounted Amount: " << discountAmt << endl;
    cout << "Final Cost: " << finalCost << endl;
    cout << "Points reset back to: " << points << endl;
    AddPoints(finalCost);
    return true;
}

