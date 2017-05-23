#include <iostream>
using namespace std;

//=======================
// Habit cost calculator
//=======================
int main(){

    //gets user input
    int age = 0;
    int dollarsPerDay = 0;
    string habit = " ";
    cout << "How old are you? ";
    cin >> age;
    cout << "What is our habit (one word)? ";
    cin >> habit;
    cout << "How many $ per day does your habit cost? ";
    cin >> dollarsPerDay;


    //calculates costs
    const int DAYS_PER_YEAR = 365;
    const int MOVIE_PRICE = 11;
    const int OLD_AGE = 90;
    int annualCost = 0;
    int yearsLeftToOldAge = 0;
    int lifeTimeCost = 0;
    int freeMovies = 0;

    annualCost = dollarsPerDay*DAYS_PER_YEAR;
    yearsLeftToOldAge = OLD_AGE-age;
    lifeTimeCost = yearsLeftToOldAge*DAYS_PER_YEAR*dollarsPerDay;
    freeMovies = lifeTimeCost/MOVIE_PRICE;


    //outputs results
    cout << endl;
    cout << "This year your " << habit << " habit will cost you $" << annualCost << "." << endl;
    cout << "Between now and when you are " << OLD_AGE << ", it will cost you $" << lifeTimeCost << "!" << endl;
    cout << "That's " << freeMovies << " \"free\" movies by when you are " << OLD_AGE << "!" << endl;



    return 0;
}