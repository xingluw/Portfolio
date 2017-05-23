#include <iostream>
#include <iomanip>
#include "ansiicodes.h"

using namespace std;

//===========================
// Lemonade cost calculator
//===========================
int main() {

    //title
    cout << ANSII_MAGENTA << "Menu:" << endl;
    cout << "*******************" << endl;
    cout << ANSII_BLUE << "New-age lemonade sizes:" << endl;


    //lemonade prices
    const int SMALL_PRICE_DOLLARS = 1;
    const int MED_PRICE_DOLLARS = 2;
    const int LARGE_PRICE_DOLLARS = 8;

    cout << ANSII_GREEN;
    cout << "  Small:  $" << SMALL_PRICE_DOLLARS << endl;
    cout << "  Medium: $" << MED_PRICE_DOLLARS << endl;
    cout << "  Large:  $" << LARGE_PRICE_DOLLARS << endl << endl;


    //gets buyer's order
    int orderSmall = 0;
    int orderMed = 0;
    int orderLarge = 0;

    cout << ANSII_BLUE << "Enter number of drinks purchased..." << endl;
    cout << ANSII_NORMAL;
    cout <<  "  # Small:  ";
    cin >> orderSmall;
    cout <<  "  # Medium: ";
    cin >> orderMed;
    cout <<  "  # Large:  ";
    cin >> orderLarge;
    cout << endl;


    //repeats the order
    const int QUANTITY_WIDTH = 3;
    cout << ANSII_BLUE << "Your order is:" << endl;
    cout << ANSII_NORMAL;
    cout << "  Small:  " << setw(QUANTITY_WIDTH) << orderSmall << " @ $" << SMALL_PRICE_DOLLARS << " each" << endl;
    cout << "  Medium: " << setw(QUANTITY_WIDTH) << orderMed << " @ $" << MED_PRICE_DOLLARS << " each" << endl;
    cout << "  Large:  " << setw(QUANTITY_WIDTH) << orderLarge << " @ $" << LARGE_PRICE_DOLLARS << " each" << endl;


    //calculates tax
    const int SMALL_PRICE_CENTS = 100;
    const int MED_PRICE_CENTS = 200;
    const int LARGE_PRICE_CENTS = 800;
    const int TAX_PERCENTAGE = 12;
    const int TOTAL_PERCENTAGE = 100;

    int subtotalCents = 0;
    int taxCents = 0;
    int totalPrice = 0;

    subtotalCents = (orderSmall*SMALL_PRICE_CENTS) + (orderMed*MED_PRICE_CENTS) + (orderLarge*LARGE_PRICE_CENTS);
    taxCents = (subtotalCents*TAX_PERCENTAGE)/TOTAL_PERCENTAGE;
    totalPrice = taxCents + subtotalCents;


    //convert to dollars to display
    const int CENTS_TO_DOLLARS = 100;
    int subtotalDollars = 0;
    int taxDollars = 0;
    int totalPriceDollars = 0;
    int subtotalCentsLeft = 0;
    int taxCentsLeft = 0;
    int totalPriceCentsLeft = 0;

    subtotalDollars = subtotalCents/CENTS_TO_DOLLARS;
    taxDollars = taxCents/CENTS_TO_DOLLARS;
    totalPriceDollars = totalPrice/CENTS_TO_DOLLARS;

    subtotalCentsLeft = subtotalCents%CENTS_TO_DOLLARS;
    taxCentsLeft = taxCents%CENTS_TO_DOLLARS;
    totalPriceCentsLeft = totalPrice%CENTS_TO_DOLLARS;


    //display results
    const int DOLLAR_WIDTH = 3;
    const int CENT_WIDTH = 2;

    cout << ANSII_BLUE << "Amount owing:" << endl;
    cout << ANSII_NORMAL;
    cout << "  Subtotal: $" << setfill(' ') << setw(DOLLAR_WIDTH) << subtotalDollars << ".";
    cout << setfill('0') << setw(CENT_WIDTH) << subtotalCentsLeft << endl;
    cout << "  Tax:      $" << setfill(' ') << setw(DOLLAR_WIDTH) << taxDollars << ".";
    cout << setfill('0') << setw(CENT_WIDTH) << taxCentsLeft << endl;
    cout << "  Total:    $" << setfill(' ') << setw(DOLLAR_WIDTH) << totalPriceDollars << ".";
    cout << setfill('0') << setw(CENT_WIDTH) << totalPriceCentsLeft << endl;


    return 0;
}
