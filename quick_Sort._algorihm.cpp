#include <iostream>
using namespace std;
int partitionGame(int arr[], int low, int high)
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
            swap(arr[p], arr[q]);
        }
    }
    swap(arr[low], arr[q]);
    return q;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionGame(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main()
{
    int arr[5] = {4, 2, 3, 1, 5};
    quickSort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}