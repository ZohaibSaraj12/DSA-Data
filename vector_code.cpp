#include <iostream>
using namespace std;
int main() {
    int* arr = new int [3];
    int capacity = 3;
    int currentent = 0;
    int value;

    cout << "Enter values (max size 3) Enter -1 To Stop: " << endl;
    while (true) {
       cout << "Enter A ("<< currentent + 1 << ") value: ";
        cin >> value;

        if (value == -1) {
            break;
        }
        arr[currentent] = value;
        currentent++;

        if (currentent == capacity) {
            capacity *= 2;
            int* tempArr = new int [capacity];

            for (int i = 0; i < currentent; i++) {
                tempArr[i] = arr[i];
            }
            delete[] arr;
            arr= tempArr;
        } 
    }


    if (currentent < capacity) {
    int* fArray = new int [currentent];
    for (int i = 0; i < currentent; i++) {
        fArray[i] = arr[i];
    }
    delete[] arr;
    arr = fArray;
    for (int i = 0; i < currentent; i++) {
    }

        cout << arr[i] << " ";
    }
    cout << "\nSize of Array is: " << currentent << " " << endl;
    delete[] arr;
    return 0;
}