#include <iostream>
using namespace std;
int main() {
    int arr[5];
    cout << "Enter Elements of an Array: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    int start = 0;
    int end = 4;
    for(;start <= end; start++, end--) {
         swap(arr[start], arr[end]);
        
        // int temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;
        
    }
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}