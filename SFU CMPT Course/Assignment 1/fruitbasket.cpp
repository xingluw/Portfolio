#include <iostream>
#include <iomanip>
#include "ansiicodes.h"
using namespace std;

//========================
// Fruit Box Calculator
//========================

int main(){

    cout << ANSII_MAGENTA << ANSII_BOLD;
    cout << "**************************" << endl;
    cout << "Local Fruit Box Calculator" << endl;
    cout << "**************************" << endl << endl;


    // Collects the fruit data
    int applesDonated = 0;
    int orangesDonated = 0;
    int fruitPiecesPerBasket = 0;

    cout << ANSII_NORMAL;
    cout << "Enter the number of " << ANSII_CYAN << "apples donated" << ANSII_NORMAL << ": ";
    cin >> applesDonated;
    cout << "Enter the number of " << ANSII_CYAN << "oranges donated" << ANSII_NORMAL << ": ";
    cin >> orangesDonated;
    cout << "Enter the number of " << ANSII_CYAN << "fruit pieces per basket" << ANSII_NORMAL << ": ";
    cin >> fruitPiecesPerBasket;


    // Repeats the fruit data
    cout << endl << ANSII_MAGENTA << ANSII_BOLD;
    cout << "Input Values:" << endl;
    cout << "-------------" << endl;

    cout << ANSII_NORMAL << "# Apples Donated:          " << ANSII_BLUE << setw(4) << applesDonated << endl;
    cout << ANSII_NORMAL << "# Oranges Donated:         " << ANSII_BLUE << setw(4) << orangesDonated << endl;
    cout << ANSII_NORMAL << "# Fruit Pieces per Basket: " << ANSII_BLUE << setw(4) << fruitPiecesPerBasket << endl;


    // Math for baskets
    int basketsToCreate = 0;
    int minApplesPerBasket = 0;
    int minOrangesPerBasket = 0;
    int ribbons = 0;
    int totalFruit = 0;
    int piecesToCompleteExtraBasket = 0;

    basketsToCreate = (applesDonated + orangesDonated)/fruitPiecesPerBasket;
    minApplesPerBasket = applesDonated/basketsToCreate;
    minOrangesPerBasket = orangesDonated/basketsToCreate;
    ribbons = basketsToCreate * 3;
    totalFruit = applesDonated + orangesDonated;
    piecesToCompleteExtraBasket = ((basketsToCreate + 1)*fruitPiecesPerBasket) - totalFruit;


    // Output results
    cout << endl << ANSII_MAGENTA << ANSII_BOLD;
    cout << "Basket Creation Numbers:" << endl;
    cout << "------------------------" << endl;

    cout << ANSII_NORMAL << "# Baskets to create:       " << ANSII_BLUE << setw(4) << basketsToCreate << endl;
    cout << ANSII_NORMAL << "Min # apples per basket:   " << ANSII_BLUE << setw(4) << minApplesPerBasket << endl;
    cout << ANSII_NORMAL << "Min # oranges per basket:  " << ANSII_BLUE << setw(4) << minOrangesPerBasket << endl;
    cout << ANSII_NORMAL << "# Ribbons to tie baskets:  " << ANSII_BLUE << setw(4) << ribbons << endl;
    cout << ANSII_NORMAL << "# Pieces needed to complete one more basket: " << ANSII_BLUE << setw(4) << piecesToCompleteExtraBasket << endl;


    return 0;
}