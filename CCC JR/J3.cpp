#include <iostream>
using namespace std;

//Problem J3: Exactly Electrical

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int t = 0;

    cout << "a:";
    cin >> a;
    cout << "b:";
    cin >> b;
    cout << "c:";
    cin >> c;
    cout << "d:";
    cin >> d;
    cout << "t:";
    cin >> t;

    int distX = abs(c-a);
    int distY = abs(d-b);

    //distX + distY + 2z = t is true, if z >= 0
    if (t >= distX + distY){
        t = t - distX - distY;
        if (t%2 == 0){
            cout << "Y";
        } else {
            cout << "N";
        }
    } else {
        cout << "N";
    }
}
