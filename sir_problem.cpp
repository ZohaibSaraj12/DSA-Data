#include <iostream>
using namespace std;
int main() {
    int* arr = new int[10]; 
    int capacity = 10;     
    int current = 0;        
    int value;

     cout << "You can enter integers (min Size is 10) But you can Enter More. Enter -1 to stop: " <<  endl;

    while (true) {
        if (current == capacity) {
        
            int nc = capacity * 2;
            int* temp = new int[nc];

            
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

           
            delete[] arr;
            arr = temp;
            capacity = nc; 
        }

         cout << "Enter value (" << (current + 1) << "): ";
         cin >> value;

        
        if (value == -1) {
            break;
        }
        
        arr[current] = value;
        current = current + 1;
    }

    
     cout << "The elements in the array are: ";
    for (int i = 0; i < current; i++) {
         cout << arr[i] << " ";
    }

    
     cout << "\ncurrent capacity: " << capacity <<  endl;
     cout << "current size: " << current <<  endl;

   
    delete[] arr;

    return 0;
}
