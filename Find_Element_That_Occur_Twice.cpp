#include <iostream>
using namespace std;
int findElement(int arr[], int size) {
    int ans = 0; 
    for (int i = 0; i < size; i++) {
        ans = ans ^ arr[i];

    }
    int ans1 = 0;
    for (int i = 1; i < size; i++) {
        ans1 = ans1 ^ i;

    }
    return ans ^ ans1;
}
int main() {
    int arr[] = {1,2,2,3};
    int size = sizeof(arr)/sizeof(int);
    int value = findElement(arr, size);
    cout << "The Element is: " << value << endl;
    return 0;
}