#include <iostream>
using namespace std;

class Heap {
    int size;
    int arr[100];

    Heap()
    {
        size = 0;
    }
    void input(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;
        
        while (index > 1)
        {
            
        }
    }
};