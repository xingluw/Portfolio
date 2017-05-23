#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//=======================
// Vector Statistics
//=======================


//functions
vector<float> readVectorOfFloats();
void displayNumbers(vector<float> numbers);
bool orderAscend(vector<float> numbers);
bool orderDescend(vector<float> numbers);

float findAvgVal(vector<float> numbers);
float findMinVal(vector<float> numbers);
float findMaxVal(vector<float> numbers);

int duplicateCount(vector<float> numbers, float value);
float findMedian(vector<float> numbers);
void removeDuplicates(vector<float> &numbers);

void displayStatistics(vector<float> numbers);


//main function
int main() {
    // Read in the values:
    vector<float> userNumbers = readVectorOfFloats();

    // Display the output
    displayStatistics(userNumbers);

    return 0;
}

//read vector of floats
vector<float> readVectorOfFloats(){
    float number;
    const int SENTINEL = 0;
    vector<float> numList;

    cout << "Enter value (0 to end): ";
    while (true) {
        cin >> number;
        if (number == SENTINEL){
            break;
        }
        numList.push_back(number);
    }
    return numList;
}

//display numbers
void displayNumbers(vector<float> numbers){
    const int DECIMALS = 2;
    const int WIDTH = 7;
    const int COLUMN_WIDTH = 8;
    int vectorLength = 0;
    int columnCount = 0;
    int lastVectorNum = 0;

    vectorLength = numbers.size();
    lastVectorNum = vectorLength - 1;
    cout << fixed << setprecision(DECIMALS) << "\t";

    //loop through vector and print out each value
    for (int i = 0; i < vectorLength; i++){
        //check if new line is needed
        if(columnCount == COLUMN_WIDTH){
            cout << endl << "\t";
            columnCount = 0;
        }

        cout << setw(WIDTH) << numbers.at(i);
        if (i != (lastVectorNum)){
            cout << ",";
        }

        columnCount++;
    }
}

//check for ascending order
bool orderAscend(vector<float> numbers){
    bool ascend = true;
    int vectorLength = 0;
    float currentNum = 0;

    vectorLength = numbers.size();

    //check if vector is 0 length
    if (vectorLength == 0){
        return ascend;
    }

    currentNum = numbers.at(0);

    for (int i = 1; i < vectorLength; i++){
        if(numbers.at(i) <= currentNum){
            ascend = false;
        }
        currentNum = numbers.at(i);
    }

    return ascend;
}

//check for descending order
bool orderDescend(vector<float> numbers){
    bool descend = true;
    int vectorLength = 0;
    float currentNum = 0;

    vectorLength  = numbers.size();

    //check if vector is 0 length
    if (vectorLength == 0){
        return descend;
    }

    currentNum = numbers.at(0);

    for (int i = 1; i < vectorLength; i++){
        if(numbers.at(i) >= currentNum){
            descend = false;
        }
        currentNum = numbers.at(i);
    }

    return descend;
}

//calculate average
float findAvgVal(vector<float> numbers){
    float avgVal = 0;
    int vectorLength = 0;
    float sum = 0;

    vectorLength = numbers.size();
    if (vectorLength == 0){
        return 0;
    }

    //loop through and add up
    for (int i = 0; i < vectorLength; i++){
        sum += numbers.at(i);
    }

    //divide by total
    avgVal = sum/vectorLength;
    return avgVal;
}

//calculate minimum
float findMinVal(vector<float> numbers){
    float minVal = 0;
    int vectorLength = 0;

    vectorLength = numbers.size();
    if (vectorLength == 0){
        return 0;
    }

    minVal = numbers.at(0);
    //loop through and find minimum
    for (int i = 0; i < vectorLength; i++){
        if (minVal > numbers.at(i)){
            minVal = numbers.at(i);
        }
    }

    return minVal;
}

//calculate maximum
float findMaxVal(vector<float> numbers){
    float maxVal = 0;
    int vectorLength = 0;

    vectorLength = numbers.size();
    if (vectorLength == 0){
        return 0;
    }

    maxVal = numbers.at(0);
    //loop through and find maximum
    for (int i = 0; i < vectorLength; i++){
        if (maxVal < numbers.at(i)){
            maxVal = numbers.at(i);
        }
    }

    return maxVal;
}

//count number of times a value is present
int duplicateCount(vector<float> numbers, float value){
    int duplicates = 0;
    int vectorLength = 0;

    vectorLength = numbers.size();

    for (int i = 0; i < vectorLength; i++){
        if (numbers.at(i) == value){
            duplicates++;
        }
    }

    return duplicates;
}

//get most common value
float findMedian(vector<float> numbers){
    float median = 0;
    int duplicates = 0;
    int vectorLength = 0;

    vectorLength = numbers.size();

    if (vectorLength == 0){
        return 0;
    }

    for (int i = 0; i < vectorLength; i++){
        if(duplicates < duplicateCount(numbers, numbers.at(i))){
            duplicates = duplicateCount(numbers, numbers.at(i));
            median = numbers.at(i);
        }
    }
    return median;
}

//remove duplicates
void removeDuplicates(vector<float> &numbers){
    int vectorLength = 0;

    vectorLength = numbers.size();
    for (int i = 0; i < vectorLength; i++){
        //if there is more than 1, erase and restart loop
        if(duplicateCount(numbers, numbers.at(i)) > 1){
            numbers.erase(numbers.begin() + i);

            //reset vector length and loop
            vectorLength = numbers.size();
            i = -1;
        }
    }
}

//display statistics
void displayStatistics(vector<float> numbers){
    const int WIDTH_1 = 20;
    const int WIDTH_2 = 7;
    const int WIDTH_3 = 4;
    const int DECIMALS = 2;
    string isAscending = "No";
    string isDescending = "No";
    vector<float> numbersCopy;
    numbersCopy = numbers;

    cout << endl;
    cout << "***********************************" << endl;
    cout << "Analysis of the numbers:" << endl;
    cout << "***********************************" << endl << endl;
    cout << "Values:" << endl;
    cout << "-------" << endl;

    displayNumbers(numbers);

    cout << endl << endl << fixed << setprecision(DECIMALS);
    cout << "Statistics on those numbers:" << endl;
    cout << "----------------------------" << endl;
    cout << setw(WIDTH_1) << "Maximum:" << setw(WIDTH_2) << findMaxVal(numbers) << endl;
    cout << setw(WIDTH_1) << "Minimum:" << setw(WIDTH_2) << findMinVal(numbers) << endl;
    cout << setw(WIDTH_1) << "Average:" << setw(WIDTH_2) << findAvgVal(numbers) << endl << endl;

    //check if it is ascending or descending
    if (orderAscend(numbers)){
        isAscending = "Yes";
    }
    if (orderDescend(numbers)){
        isDescending = "Yes";
    }
    cout << setw(WIDTH_1) << "Is ascending:" << setw(WIDTH_2) << isAscending << endl;
    cout << setw(WIDTH_1) << "Is descending:" << setw(WIDTH_2) << isDescending << endl << endl;

    cout << "Data with duplicates removed:" << endl;
    cout << "-----------------------------" << endl;
    removeDuplicates(numbersCopy);
    displayNumbers(numbersCopy);
    cout << endl << endl;

    cout << "Repetition counts in user data:" << endl;
    cout << "-------------------------------" << endl;
    cout << "\tMost common value is " << findMedian(numbers) << "!" << endl << endl;

    //check repetition count for duplicates removed
    int vectorLength = 0;
    vectorLength = numbersCopy.size();

    for (int i = 0; i < vectorLength; i++){
        cout << "The value" << setw(WIDTH_2) << numbersCopy.at(i) << " occurs";
        cout << setw(WIDTH_3) << duplicateCount(numbers, numbersCopy.at(i));
        cout << " time(s)." << endl;
    }

}

