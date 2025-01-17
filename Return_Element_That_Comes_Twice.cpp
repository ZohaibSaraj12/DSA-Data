// 1st Approach XOR
#include <iostream>
using namespace std;
int returnElementComesTwice(int arr[], int size) {
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans = ans ^ arr[i];
    }
    for (int i = 1; i < size; i++) {
        ans = ans ^ i;
    }
    return ans;
}
int main() {
    int arr[] = {1,2,2,3,4};
    int size = sizeof(arr) / sizeof(int);
    int value = returnElementComesTwice(arr, size);
    cout << "Element is: " << value << endl;
    return 0;
}