// shell sort practice 

#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> arr = {5, 3, 1, 2, 4};

    for (int gap = arr.size() / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < arr.size(); i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }

    for (const auto& i : arr)
    {
        cout << i << " ";
    }

}