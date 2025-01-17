// A sorting technique in which we compare the first of element of array to the next element and if greater
// We swap if element at first place greater than element present at the second place 
// Implementing using vectors second name of dynamic arrays which set size dynamically 

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    
    
    vector<int>arr = {4, 3, 2};
    for (int i = 0; i < arr.size() - 1; i++)
    {
        bool swapped = false;

        for (int j = 0 ; j < arr.size() - i - 1; j++)
        {
            
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
               
            }
        }
        if (!swapped)
        {
            break;
        }
    }
   
    cout << "final sorted Array: " << endl;
    for (const auto& num : arr)
    {
        cout << num << " ";
    }
}