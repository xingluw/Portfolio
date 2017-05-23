#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include "ansiicodes.h"

using namespace std;

//========================
// Dice Game
//========================

//display welcome message
void displayWelcome(){
    cout << ANSII_BOLD << ANSII_MAGENTA;
    cout << "********************************************" << endl;
    cout << "Welcome to Roller's Un-Random house of dice!" << endl;
    cout << "********************************************" << endl;
    cout << ANSII_NORMAL;
}

//asks for username and returns
string getUserName(){
    string name = " ";
    cout << "What is your first name? ";
    cin >> name;
    return name;
}

//chooses a seed for random generator
void seedGame(){
    int seed;
    cout << "Would you like to pick an un-random game, or let the timer pick?" << endl;
    cout << "Enter 0 for timer, or pick your own un-random game: ";
    cin >> seed;
    if (seed == 0){
        srand(time(nullptr));
        cout << "THE TIMER! A daring choice!" << endl << endl;
    } else {
        srand(seed);
        cout << seed << "! A wise and safe choice." << endl << endl;
    }
}

//return random number between 1 and 6
int getRandomRoll(){
    const int MAX_VAL = 6;
    const int INCREASE = 1;
    int randomRoll = 0;
    randomRoll = (rand() % MAX_VAL + INCREASE);
    return randomRoll;
}

//asks and returns maximum bet
int getMaxBet(){
    int maxBet = 0;
    while (maxBet < 1){
        cout << "What would you like to be the maximum bet? :";
        cin >> maxBet;
        if (maxBet >= 1){
            return maxBet;
        }
        cout << ANSII_RED << "The maximum bet must be greater than or equal to 1." << endl << ANSII_NORMAL;
    }
}

//gets and returns the user's bet
int getUserBet(int currentScore, int maxBet) {
    int userBet = 0;
    while (userBet < 1 || userBet > maxBet || userBet > currentScore) {
        cout << "Enter your bet: ";
        cin >> userBet;

        if (userBet < 1) {
            cout << ANSII_RED << "Your bet must be at least 1." << ANSII_NORMAL << endl;
        } else if (userBet > maxBet) {
            cout << ANSII_RED << "You must not bet more than the maximum bet (" << maxBet << ")." << ANSII_NORMAL << endl;
        } else if (userBet > currentScore) {
            cout << ANSII_RED << "You must not bet more than your score (" << currentScore << ")." << ANSII_NORMAL << endl;
        } else {
            return userBet;
        }
    }
}


//main loop
int main(){
    //initialization
    int maxBet = 0;
    int currentPoints = 50;
    int roundNumber = 1;

    displayWelcome();
    string userName = getUserName();
    seedGame();
    maxBet = getMaxBet();
    cout << endl;


    //game loop
    while (currentPoints > 0 && currentPoints < 100){
        //set up rolls
        int dealerRollOne = getRandomRoll();
        int dealerRollTwo = getRandomRoll();
        int userRollOne = getRandomRoll();
        int userRollTwo = getRandomRoll();

        int dealerRollSum = dealerRollOne + dealerRollTwo;
        int userRollSum = userRollOne + userRollTwo;
        const int SUM_WIDTH = 2;
        int userBet = 0;

        //round begins
        cout << ANSII_BLUE << "Round " << roundNumber << ANSII_NORMAL <<" You have " << ANSII_CYAN << currentPoints << ANSII_NORMAL << " points." << endl;
        cout << "Dealer rolls: " << dealerRollOne << " + " << dealerRollTwo << " = " << setw(SUM_WIDTH) << dealerRollSum;
        cout << "           ";
        userBet = getUserBet(currentPoints, maxBet);
        cout << "You roll:     " << userRollOne << " + " << userRollTwo << " = " << setw(SUM_WIDTH) << userRollSum << "." << endl;

        //evaluates win/lose round
        if(userRollSum > dealerRollSum){
            cout << ANSII_GREEN << userName << ", you won! :-)" << ANSII_NORMAL << endl;
            currentPoints = currentPoints + userBet;
        } else {
            cout << ANSII_RED << userName << ", you lost! :-(" << ANSII_NORMAL << endl;
            currentPoints = currentPoints - userBet;
        }
        cout << "Current score: " << currentPoints << "." << endl << endl;
        roundNumber++;
    }


    //game end message
    if (currentPoints >= 100){
        cout << ANSII_BOLD << ANSII_GREEN << "Congratulations " << userName;
        cout << "! You win the game with a score of " << currentPoints << "." << endl;
    } else {
        cout << ANSII_BOLD << ANSII_RED << "I'm sorry, " << userName;
        cout << "; you are out of points so you lose." << endl;
    }


    return 0;
}