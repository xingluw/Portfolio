#include <iostream>
#include <vector>
using namespace std;

int main(){
    int jerseyTotal;
    int athleteTotal;
    vector<string> jerseyList;
    vector<string> orderSizes;
    vector<int> orderNums;
    vector<int> jerseyNumWants;

    cin >> jerseyTotal;
    cin >> athleteTotal;

    for (int i = 0; i < jerseyTotal; i++){
        string input = "";
        cin >> input;
        jerseyList.push_back(input);
    }

    for (int i = 0; i < athleteTotal; i++){
        string tempSize = "";
        int tempJNum = 0;

        cin >> tempSize;
        orderSizes.push_back(tempSize);
        cin >> tempJNum;
        orderNums.push_back(tempJNum);
        jerseyNumWants.push_back(0);
    }

    for (int i = 0; i < athleteTotal; i++) {
        int jerseyNum = orderNums.at(i);
        string size = "";
        size = jerseyList.at(jerseyNum - 1);

        if (orderSizes.at(i) == "S") {
            if (size == "S" || size == "M" || size == "L") {
                jerseyNumWants.at(jerseyNum - 1) += 1;
            }
        } else if (orderSizes.at(i) == "M") {
            if (size == "M" || size == "L") {
                jerseyNumWants.at(jerseyNum - 1) += 1;
            } else if (orderSizes.at(i) == "L" && size == "L") {
                jerseyNumWants.at(jerseyNum - 1) += 1;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < athleteTotal; i++){
        if (jerseyNumWants.at(i) != 0){
            if (sum == 0){
                sum = 1;
            }
            sum *= jerseyNumWants.at(i);
        }
    }

    cout << sum;

    return 0;
}
