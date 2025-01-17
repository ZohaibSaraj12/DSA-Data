#include <iostream>
using namespace std;
int partition(int arr[], int low, int high)
{
    // Selecting Pivot as the starting element
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left <= right)
    {
        while (left <= right && arr[left] <= pivot)
        {
            left++;
        }
        while (left <= right && arr[right] > pivot)
        {
            right--;
        }
        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[low], arr[right]);
    return right;
}
void quickSort(int arr[], int low, int high)
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
    const int n = 6;
    int arr[n] = {5, 3, 4, 6, 7, 8};

    quickSort(arr, 0, n - 1);

    for (const auto &num : arr)
    {
        cout << num << " ";
    }
    return 0;

    // Closure of the main
}