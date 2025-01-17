#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr;
    int size;
    cout << "Enter how many do you want to enter: " << endl;
    cin >> size;
    cout << "Enter Elements" << endl;
    for (int i = 0; i < size; i++)
    {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    int n = arr.size();
    
    
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
    
    cout << "Final Sorted Array: " << endl;
    for (const auto& num : arr)
    {
        cout << num << " ";
    }

}