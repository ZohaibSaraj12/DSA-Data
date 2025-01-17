#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {4, 5, 3, 1, 2};
    int temp = 0;
    for (int gap = arr.size() / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < arr.size(); i++)
        {
            temp = arr[i];
            int j = i;


            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
    cout << "Final Sorted Array : " << endl;
    for (const auto& num : arr)
    {
        cout << num << " ";
    }
    return 0;
}