#include <iostream>
using namespace std;

//Problem J1: Quadrant Selection

int main() {
    int x = 0;
    int y = 0;

    cout << "Enter X: ";
    cin >> x;
    cout << "Enter Y: ";
    cin >> y;

    if (x > 0){
        if (y > 0){
            cout << "1";
        } else {
            cout << "4";
        }
    } else {
        if (y > 0){
            cout << "2";
        } else {
            cout << "3";
        }
    }
    return 0;
}