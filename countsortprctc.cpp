#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int>arr = {3, 2, 1, 4, 5, 7};
    vector<int>output(arr.size());
    int minValue = *min_element(arr.begin(), arr.end());
    int maxValue = *max_element(arr.begin(), arr.end());

    int range = maxValue - minValue + 1;

    vector<int> count(range, 0);

    for (auto num : arr)
    {
        count[num - minValue]++;
    }
    for (int i = 1; i < range; i++)
    {
        count[i] = count[i] + count[i - 1]; 
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - minValue] - 1] = arr[i];
        count[arr[i] - minValue]--;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = output[i];
    }
    
    cout << "sorted array is: " << endl;
    for (const auto& num : arr)
    {
        cout << num << " ";
    }

}