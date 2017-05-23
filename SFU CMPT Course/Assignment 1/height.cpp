#include <iostream>
#include "ansiicodes.h"

using namespace std;

//==============================================================
// Converts the user's  height from inches to feet and inches
//==============================================================


int main() {

    // Gets the user's height in inches
    int heightInInches = 0;
    cout << "Enter your height " << ANSII_RED << "(inches)" << ANSII_NORMAL << ": ";
    cin >> heightInInches;


    // Converts to feet and inches and outputs
    int heightInFeet = 0;
    int heightInchesLeftover = 0;
    heightInFeet = heightInInches / 12;
    heightInchesLeftover = heightInInches % 12;

    cout << "Write either: " << ANSII_BOLD << ANSII_CYAN;
    cout << "\"I'm " << heightInFeet << "\'" << heightInchesLeftover << "\"!\"";
    cout << ANSII_NORMAL << " \\ " << ANSII_BOLD << ANSII_GREEN;
    cout << "\"I'm " << heightInInches << "\"" << " tall!\"" << endl;

    return 0;
}