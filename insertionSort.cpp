#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int steps = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        bool swapped = false;
       
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            swapped = true;
        }
        steps++;
        arr[j + 1] = key;
       
        if (!swapped)
        {
            break;
        }

    }
    cout << steps << endl;
}