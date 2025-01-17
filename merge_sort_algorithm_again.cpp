// Implementation of the merge sort using the vectors that are called dynamic arrays 
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;


    vector<int> l(n1);
    vector<int> r(n2);

    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[left + i];
    }
    for (int j = 0; j < n1; j++)
    {
        r[j] = arr[mid + j + 1];
    }

    int i = 0;
    int j = 0; 
    int k = left;


    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            arr[k++] = l[i++];
        }
        else 
        {
            arr[k++] = r[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = l[i++];

    }
    while (j < n2)
    {
        arr[k++] = r[j++];
    }
}
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main()
{
    vector<int> arr = {4, 3, 2, 1, 5};
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Final Sorted Array is: " << endl;
    for (const auto& num : arr)
    {
        cout << num << " ";
    }

    return 0;
}