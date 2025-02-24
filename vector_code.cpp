#include <iostream>
using namespace std;
int main() {
    int* arr = new int [3];
    int capacity = 3;
    int current = 0;
    int value;

    cout << "Enter values (max size 3) Enter -1 To Stop: " << endl;
    while (true) {
       cout << "Enter A ("<< current + 1 << ") value: ";
        cin >> value;

        if (value == -1) {
            break;
        }
        arr[current] = value;
        current++;

        if (current == capacity) {
            capacity *= 2;
            int* tempArr = new int [capacity];

            for (int i = 0; i < current; i++) {
                tempArr[i] = arr[i];
            }
            delete[] arr;
            arr= tempArr;
        } 
    }


    if (current < capacity) {
    int* fArray = new int [current];
    for (int i = 0; i < current; i++) {
        fArray[i] = arr[i];
    }
    delete[] arr;
    arr = fArray;
    for (int i = 0; i < current; i++) {
    }

        cout << arr[i] << " ";
    }
    cout << "\nSize of Array is: " << current << " " << endl;
    delete[] arr;
    return 0;
}