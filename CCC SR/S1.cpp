#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 0;
    int sum = 0;
    cin >> n;

    vector<int> list;
    for(int i = 0; i < n; i++){
        int input = 0;
        cin >> input;
        if (input != 0){
            list.push_back(input);
        } else {
            list.pop_back();
        }
    }

    for (int i = 0; i < list.size(); i++){
        sum += list.at(i);
    }
    cout << sum;

    return 0;
}