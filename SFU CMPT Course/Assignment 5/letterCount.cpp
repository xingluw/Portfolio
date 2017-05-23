#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
#include "ansiicodes.h"

using namespace std;


//===================
// Letter Counter
//===================

//function prototypes
vector<int> countLetters(string inString);
void printLetterCount(vector<int> letters);


int main(){
    string phrase = " ";
    vector<int> letters;

    cout << "Enter your string: ";
    getline(cin, phrase);
    letters = countLetters(phrase);
    cout << "You entered: " << phrase << endl << endl;

    printLetterCount(letters);

    return 0;
}

//count letters
vector<int> countLetters(string inString){
    vector<int> letterVector;
    int stringLength = 0;
    char myLetter = ' ';
    int index = 0;
    const int TOTAL_LETTERS = 26;

    stringLength = inString.size();

    //initialize letterVector
    for (int i = 0; i < TOTAL_LETTERS; i++){
        letterVector.push_back(0);
    }


    //add to vector
    for (int i = 0; i < stringLength; i++){
        myLetter = inString.at(i);
        myLetter = toupper(myLetter);
        char baseChar = 'A';
        index = myLetter - baseChar;

        if(index < TOTAL_LETTERS && index >= 0){
            letterVector.at(index)++;
        }
    }
    return letterVector;
}


//print
void printLetterCount(vector<int> letters){
    const int TOTAL_LETTERS = 26;
    const int WIDTH = 3;

    cout << "Character Count:" << endl;
    cout << "----------------" << endl;

    char baseChar = 'A';

    for (char ch = 'A'; ch < TOTAL_LETTERS + baseChar; ch++){
        cout << setw(WIDTH) << ch;
    }

    cout << endl;
    
    const int FEW = 3;
    const int SOME = 6;
    const int MORE = 10;
    for (int i = 0; i < TOTAL_LETTERS; i++) {
        if (letters.at(i) <= FEW) {
            cout << ANSII_BLUE << setw(WIDTH) << letters.at(i) << ANSII_NORMAL;

        } else if (letters.at(i) <= SOME) {
            cout << ANSII_CYAN << setw(WIDTH) << letters.at(i) << ANSII_NORMAL;

        } else if (letters.at(i) <= MORE) {
            cout << ANSII_BOLD << ANSII_CYAN << setw(WIDTH) << letters.at(i) << ANSII_NORMAL;

        } else {
            cout << ANSII_BOLD << ANSII_YELLOW << setw(WIDTH) << letters.at(i) << ANSII_NORMAL;
        }
    }
}