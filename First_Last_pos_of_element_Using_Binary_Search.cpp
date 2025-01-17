#include <iostream>
using namespace std;
int firstOccurence (int arr[], int size, int key) {
    int start = 0; 
    int end = size - 1;
    int mid = 0;
    mid = start + (end - start) / 2;
    int ans = -1;
    
    while (start <= end) {
       mid = start + (end - start) / 2;

       if (key == arr[mid]) {
        
        ans = mid;
        end = mid - 1;

       }
       else if (key > arr[mid]) {

        start = mid + 1;

       }
       else {

        end = mid - 1;

       }
    }
    return ans;
}
int lastOccurence(int arr[], int size, int key) {
     
    int start = 0;
    int end = size - 1;
    int mid = 0;
    int ans = -1;
    mid = start + (end - start) / 2;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (key == arr[mid]) {
            ans = mid;
            start = mid + 1;
        }
        else if (key > arr[mid]) {
        start = mid + 1;

        }
        else {
            end = mid - 1;

        }
    }
    return ans;

}
int main() {
    int arr[5] = {1, 2, 5 , 5,5};
    int num = 0;
    cout << "Enter a Number you want to check Occurence in these Elements (1, 2, 3, 4, 5): ";
    cin >> num;
    int value = firstOccurence(arr, 5, num);

    cout << "FIrst Occurence of " << num << " is: " << value << endl;

    int v = lastOccurence(arr, 5, num);

    cout << "last Occurence of " << num << " is: " << v << endl;
     
     int occ = (v - value) + 1;
     cout << occ;
    
    return 0;
}