#include <iostream>
#include <cassert>
using namespace std;

// Prototypes
bool isPermutation(int arr[], int size);
void initializePermutation(int arr[], int size);
void reverseArray(int arr[], int size);
void copyArray(int destination[], int source[], int size);
int scorePermutation(int arr[], int size);
void printPermutationAndScore(int arr[], int size);
bool nextPermutation(int arr[], int size);
void demoPermutations();
void findOptimalPermutation(int arr[], int size);
void printOptimalPermutations(int low, int high);


int main() {
    const int LOW = 1;
    const int HIGH = 11;

    demoPermutations();

    // Simple tests for isPermutation()
    int arr1[] = {4, 2, 3, 1, 5};
    cout << "isPerm 1? " << isPermutation(arr1, 5) << endl;
    int arr2[] = {4, 2, 3, 5, 5};
    cout << "isPerm 2? " << isPermutation(arr2, 5) << endl;
    int arr3[] = {4, 2, 0, 1};
    cout << "isPerm 3? " << isPermutation(arr3, 4) << endl;

    printOptimalPermutations(LOW, HIGH);

    return 0;
}


// Returns 1 if arr is a permutation of 1, ..., n, and 0 otherwise.
bool isPermutation(int arr[], int size) {
    for(int i = 1; i <= size; i++){
        int indexCount = 0;
        for (int j = 0; j < size; j++){
            if (arr[j] == i){
                break;
            } else {
                indexCount++;
                if (indexCount > size-1){
                    return false;
                }
            }
        }
    }
    return true;
}


// Initialize arr[] to hold the values 1 to n, in order.
void initializePermutation(int arr[], int size) {
    for (int i = 0; i < size; i++){
        arr[i] = i + 1;
    }
}


// Reverse the array arr, changing the original array.
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size/2; i++){
        int opposite = size - 1 - i;
        int tempVal = arr[i];
        arr[i] = arr[opposite];
        arr[opposite] = tempVal;
    }
}


// Copy all elements from source[] to destination[]
void copyArray(int destination[], int source[], int size){
    for (int i = 0; i < size; i++){
        destination[i] = source[i];
    }
}


// Returns the number of reversals needed to make arr[0] == 1
// when the reversal game is played on arr.
// The array (arr) is unchanged by this function.
// Note: If arr[0] == 1 initially, then score(arr, n) returns 0
// Note: arr[] must be a permutation.
int scorePermutation(int arr[], int size){
    if (isPermutation(arr, size) == 0){
        return 0;
    }
    if (arr[0] == 1){
        return 0;
    }

    int score = 0;
    int newArr[size];
    copyArray(newArr, arr, size);
    while (newArr[0] != 1){
        reverseArray(newArr, newArr[0]);
        score++;
    }
    return score;
}


// Prints the permutation, its size, and score in the form:
//    "[n = <size>] Score of {1, 2, 3, ..., n} = <score>"
// For example, if arr = {3, 4, 5, 1, 2}
// then printPermutationAndScore(arr, 5) outputs:
//    [n = 5] Score of {3, 4, 5, 1, 2} = 3
void printPermutationAndScore(int arr[], int size){
        cout << "[size = " << size << "] Score of {";
        for (int i = 0; i < size; i++){
            cout << arr[i];
            if (i != size-1){
                 cout << ",";
            }
        }
        cout << "} = "<< scorePermutation(arr, size) << endl;
}


// Given a permutation, advance it to the next permutation in lexicographic
// order. Algorithm discussed here:
// http://stackoverflow.com/questions/352203/generating-permutations-lazily
// Return 0 if no next permutation is possible; 1 if it new permutation found.
bool nextPermutation(int arr[], int size) {
    // Check that arr[] is already a valid permutation.
    // This will crash the program if arr() is not a valid permutation.
    assert(isPermutation(arr, size));

    // Ensure the permutation is large enough to support re-ordering.
    if (size <= 1) {
        return 0;
    }

    // Find the longest tail
    int tailStartIdx = size - 1;
    while (arr[tailStartIdx - 1] > arr[tailStartIdx]) {
        tailStartIdx --;
        if (tailStartIdx == 0) {
            return 0;
        }
    }
    int swapFrontIdx = tailStartIdx - 1;

    // Find the element in the sorted tail which is the smallest element
    // larger than the element before the tail.
    int swapInTailIdx = size - 1;
    while (arr[swapInTailIdx] < arr[swapFrontIdx]) {
        swapInTailIdx --;
    }

    // Swap the elements:
    int temp = arr[swapInTailIdx];
    arr[swapInTailIdx] = arr[swapFrontIdx];
    arr[swapFrontIdx] = temp;

    // Reverse the tail:
    reverseArray(arr + tailStartIdx, size - tailStartIdx);

    return 1;
}


// Display all permutations of a specific size.
// Demonstrates how to use the permutation functions.
void demoPermutations() {
    // Create the first permutation
    const int SIZE = 4;
    int perm[SIZE];
    initializePermutation(perm, SIZE);

    // Create all possible permutations
    int counter = 1;
    bool moreToGo = true;
    while (moreToGo) {
        // Display the permutation
        cout << counter << ": ";
        for (int i = 0; i < SIZE; i++) {
            cout << perm[i] << ", ";
        }
        cout << endl;

        moreToGo = nextPermutation(perm, SIZE);
        counter++;
    }
}


// Find an optimal permutation (of size n) and copy it into arr[].
// If more than one permutation maximizes the score, then any
// one of the maximizing permutations may be selected.
// The contents of arr [] do not matter when called; it will
// contain the maximizing permutation when done (it is output only).
void findOptimalPermutation(int arr[], int size){
    int score = scorePermutation(arr, size);
    int newScore = 0;
    int copyArr[size];
    bool moreToGo = nextPermutation(arr, size);
    if (!moreToGo){
        return;
    }
    while (moreToGo) {
        newScore = scorePermutation(arr, size);
        if (newScore > score){
            score = newScore;
            copyArray(copyArr, arr, size);
        }
        moreToGo = nextPermutation(arr, size);
    }
    copyArray(arr, copyArr, size);
}


// Test all permutations of sizes between low and high (inclusive).
// For each size, print one permutation which maximizes it score.
void printOptimalPermutations(int low, int high){
    for (int i = low; i <= high; i++){
        int arr[i];
        initializePermutation(arr, i);
        findOptimalPermutation(arr, i);
        printPermutationAndScore(arr, i);
    }
}