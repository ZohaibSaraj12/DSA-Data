#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int p = low + 1;
    int q = high;
    while (p <= q)
    {
        while (p <= q && arr[p] <= pivot)
        {
            p++;
        }
        while (p <= q && arr[q] > pivot)
        {
            q--;
        }
        if (p < q)
        {
            swap (arr[p], arr[q]);
        }
    }

    swap(arr[low], arr[q]);
    return q;
}
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main()
{
    vector<int> arr = {4, 3, 1, 5, 2};
    quickSort(arr, 0, arr.size() - 1);

    cout << "Final sorted Array is: " << endl;
    for (const auto& num : arr)
    {
        cout << num << " ";
    }
    
}