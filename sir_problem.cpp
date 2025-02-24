#include <iostream>
using namespace std;
int main() {
    int* arr = new int[10]; 
    int capacity = 10;     
    int currentent = 0;        
    int value;

     cout << "You can enter integers (min Size is 10) But you can Enter More. Enter -1 to stop: " <<  endl;

    while (true) {
        if (currentent == capacity) {
        
            int nc = capacity * 2;
            int* temp = new int[nc];

            
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

           
            delete[] arr;
            arr = temp;
            capacity = nc; 
        }

         cout << "Enter value (" << (currentent + 1) << "): ";
         cin >> value;

        
        if (value == -1) {
            break;
        }
        
        arr[currentent] = value;
        currentent = currentent + 1;
    }

    
     cout << "The elements in the array are: ";
    for (int i = 0; i < currentent; i++) {
         cout << arr[i] << " ";
    }

    
     cout << "\ncurrentent capacity: " << capacity <<  endl;
     cout << "currentent size: " << currentent <<  endl;

   
    delete[] arr;

    return 0;
}
