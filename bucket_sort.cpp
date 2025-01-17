// Improved, entirely Optimized Bucket Sort Algorithm using vectors
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<float> arr = {0.20, 0.03, 0.01, 1.0, 0.4};
    const int bucketCount = 10;
    vector<float> buckets[bucketCount];

    for (int i = 0; i < arr.size(); i++)
    {
        int bucketIndex = arr[i] * bucketCount;
        if (bucketIndex == bucketCount)
        {
            cout << "You can't Use 1.0 Continuing Other Array" << endl;
            cout << "1.0 Present at " << i << " index so removing 1.0 and continuing the whole array" << endl;
            arr.erase(arr.begin() + i);
            continue;
        }
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < bucketCount; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;

    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[index++] = buckets[i][j];
        }
    }

    cout << "Sorted Elements Are: " << endl;
    for (const auto &n : arr)
    {
        cout << n << " ";
    }
    return 0;
}