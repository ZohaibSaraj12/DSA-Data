#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int>& arr) {
    int low = 0,   = 0, high = arr.size() - 1;

    // Traverse the array
    while (  <= high) {
        if (arr[ ] == 0) {
            swap(arr[low], arr[ ]);  // Swap 0 to the front
            low++;
             ++;
        } 
        else if (arr[ ] == 1) {
             ++;  // Leave 1 in the  dle
        } 
        else {
            swap(arr[ ], arr[high]);  // Swap 2 to the back
            high--;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sort012(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
