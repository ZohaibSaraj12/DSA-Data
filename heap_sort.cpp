#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int parent = i;
    int p = i * 2 + 1;
    int q = i * 2 + 2;

    if (p < n && arr[parent] < arr[p])
    {
        parent = p;
    }
    if (q < n && arr[parent] < arr[q])
    {
        parent = q;
    }
    if (parent != i)
    {
        swap(arr[parent], arr[i]);
        heapify(arr, n, parent);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    int size = n - 1;

    while (size  > 0)
    {
        swap(arr[0], arr[size]);
        size--;
        heapify(arr, size + 1, 0);
    }
}
int main()
{
    int arr[6] = {5, 4, 20, 50, 40, 70};
    heapSort(arr, 6);

    cout << "Printing Sorted array" << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}