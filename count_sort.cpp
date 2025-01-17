#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr = {2, -1, 4, 5, 8, 1};

    int maxValue = *max_element(arr.begin(), arr.end());
    int minValue = *min_element(arr.begin(), arr.end());
    int range = maxValue - minValue + 1;
    vector<int> count(range, 0);
    vector<int> output(arr.size());
    for (int num : arr)
    {
        // count of that number will be plus plus means incremented
        count[num - minValue]++;
    }
    
    // if we just do here i = 0 < range what is wrong we just doing 
    // count[0] = count[0] + count[0 - 1]  ----> which will be count[0] = count[0] + count[-1]
    // count[-1] is wrong coz we have no index of -1 so we start from 1 index so that 
    // it will sum all the previous together 
    for (int i = 1; i < range; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    // if not run in reverse order it will just for example ({2} a, {2} b) it will sort as ({2} b, {2} a)
    // To keep in order we just make loop work in reverse order to maintain the order of (a and b)
    for (int i = arr.size() - 1; i >= 0 ; i--)
    {   
        
        // arr[i] - minValue for offset if -ive numbers come than make them based on zero-indexed array 
        output[count[arr[i] - minValue] - 1] = arr[i];
        count[arr[i] - minValue]--;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = output[i];
    }


    cout << "Sorted Array is : " << endl;
    for (const auto& num : arr)
    {

        cout << num << " ";
        
    }

    return 0;
}

