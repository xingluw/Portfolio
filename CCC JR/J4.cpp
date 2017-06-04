#include <iostream>
using namespace std;

//Problem J4: Favourite Times
void addTime();
void displayTime();
void calculateDiff();

int a = 1;
int b = 2;
int c = 0;
int d = 0;
int total = 0;

int main() {
    int t = 0;
    cout << "Duration: ";
    cin >> t;

    for (int i = 0; i < t; i++){
        addTime();
        calculateDiff();
    }

    cout << "Total: " << total << endl;

    return 0;
}

void addTime(){
    d += 1;
    if (d == 10){
        d = 0;
        c += 1;
    }
    if (c == 6){
        c = 0;
        b += 1;
    }
    if (b == 10){
        b = 0;
        a+= 1;
    }
    if (a == 1){
        if (b == 3){
            a = 0;
            b = 1;
        }
    }
}
void displayTime(){
    if (a == 0){
        cout << b << ":" << c << d;
    } else {
        cout << a << b << ":" << c << d ;
    }
}
void calculateDiff(){
    int diff = d-c;
    if (c-b == diff){
        if (a == 0){
            displayTime();
            cout << " Difference: " << diff << endl;
            total+= 1;
        } else if (b-a == diff){
            displayTime();
            cout << " Difference: " << diff << endl;
            total += 1;
        }
    }
}