#include <iostream>
using namespace std;
void checkElement(int arr[], int size) {

    int count[100] = {0};
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    bool found = false;
    cout << "Elements Occured Twice in an array: ";
    for (int i = 0; i < size; i++) {
        if (count[i] == 2) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "No Twice Elements";
    }
    

}
int main() {
int arr[] = {1,2,2,3,3,4};
int size = sizeof(arr)/sizeof(int);
checkElement(arr, size);
return 0;
}