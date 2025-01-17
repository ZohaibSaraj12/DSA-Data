#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr = {210, 34, 2, 0, 321, 43, 78};
    vector<int> output(arr.size());
    int maxValue = *max_element(arr.begin(), arr.end());
    for (int exp = 1; (maxValue / exp) > 0; exp *= 10)
    {
    // we will make the count array for each of the places for example frist for 1's , 10's 
    // and so on 
        vector<int> count(10, 0);
        for (const auto& num : arr)
        {
            int digit = (num / exp) % 10;
            count[digit]++;
        }
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        for (int i = 0 ; i < 10; i++)
        {
            arr[i] = output[i];
        }
    } 
    for (const auto& num : arr)
    {
        cout << num << " ";
    }
}