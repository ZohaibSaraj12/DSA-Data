#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
   vector<float> arr = {0.3, 0.54, 0.36, 0.53, 0.12};
   const int bucketCount = 10;
   vector<float> bucketArray[bucketCount];

   for (int i = 0; i < arr.size(); i++)
   {
    int bucketIndex = arr[i] * bucketCount; 
    bucketArray[bucketIndex].push_back(arr[i]);
   }

   for (int i = 0; i < bucketCount; i++)
   {
    sort(bucketArray[i].begin(), bucketArray[i].end());
   }
   
   int index = 0;
   for (int i = 0; i < bucketCount; i++)
   {
    for (int j = 0; j < bucketArray[i].size(); j++)
    {
        arr[index++] = bucketArray[i][j];
    }
   }

   for (int i =0 ; i < arr.size(); i++)
   {
    cout << arr[i] << " ";
   }

}
