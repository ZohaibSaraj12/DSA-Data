#include <iostream>
#include <algorithm>
using namespace std;
void bucketSort(float arr[], int n)
{
    float buckets[10][n];
    int bucketSize[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] * 10;
        if (bucketIndex >= 10)
        {
            cout << "You can't Use 1.0 Continuing Other Array" << endl;
            cout << "1.0 Present at " << i << " index so removing 1.0 and continuing the whole array" << endl;
            continue;
        }
        buckets[bucketIndex][bucketSize[bucketIndex]++] = arr[i];
    }

    for (int i = 0; i < 10; i++)
    {
        sort(buckets[i], buckets[i] + bucketSize[i]);
    }
    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < bucketSize[i]; j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
}
int main()

{
    float arr[5] = {0.21, 0.01, 0.02, 0.43, 0.26};
    bucketSort(arr, 5);

    cout << "Final Sorted Array Is : " << endl;
    for (const auto& num : arr)
    {
        cout << num << " ";
    }
    return 0;
}