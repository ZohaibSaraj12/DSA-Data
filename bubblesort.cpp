#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the array size" << endl;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
            
        }
        if (!swapped)
        {
            break;
        }

        
        
    }
    
    cout << "sorted arrray is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}