#include <iostream>
using namespace std;
int find_Unique(int arr[], int size) {
int ans = 0;
for (int i = 0; i < size; i++) {
    ans = ans ^ arr[i];
}
return ans;
}
int main() {
    int arr[4] = {1,2,2,3};
    int value = find_Unique(arr, 4);
    cout << value;
    return 0;
}