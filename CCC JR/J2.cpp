#include <iostream>
#include <cmath>
using namespace std;

//Problem J2: Shifty Sum

int main() {
    int n = 0;
    int k = 0;
    double sum = 0;

    cout << "N:";
    cin >> n;
    cout << "k:";
    cin >> k;
    sum = n;

    for (int i = 1; i <= k; i++){
        double j = 0;
        j = n * (pow(10,i));
        sum = sum + j;
    }

    cout << "Sum = " << sum << endl;
    return 0;
}