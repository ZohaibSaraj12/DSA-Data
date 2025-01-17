#include <iostream>
#include <vector>
using namespace std;
int main()
{
    
        int pass = 0;
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
                pass++;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    cout << "passes are: " << pass << endl;
    cout << "final sorted Array: " << endl;
    for (const auto& num : arr)
    {
        cout << num << " ";
    }
}