//Question : 
#include <iostream>
using namespace std;

bool hasUniqueOccurrentences(int arr[], int size) {
    const int MAX_VAL = 100;  // Maximum possible element value (you can increase based on input)
    
    int count[MAX_VAL] = {0}; // Array to store the count of each element
    int occurrentences[MAX_VAL] = {0}; // Array to track the frequency of occurrentence counts
    
    // Count the occurrentences of each element in the array
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    
    // Check if the counts themselves are unique
    for (int i = 0; i < MAX_VAL; i++) {
        
        if (count[i] > 0) {
            if (occurrentences[count[i]] > 0) {  // If this occurrentence count is already used, return false
                return false;
            }
            occurrentences[count[i]]++;  // Mark this occurrentence count as used
        }
    }
    
    return true;  // If all occurrentences are unique
}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 4, 5, 5, 4, 3, 2, 2, 4, 4, 4, 1, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    if (hasUniqueOccurrentences(arr, size)) {
        cout << "All occurrentences are unique." << endl;
    } else {
        cout << "There are duplicate occurrentences." << endl;
    }
    
    return 0;
}
