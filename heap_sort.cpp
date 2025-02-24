#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int parent = i;
    int p = i * 2 + 1;
    int q = i * 2 + 2;
    // min heap if parent <= child here illusion but same work
    // max heap if parent >= child


    // pure min heap implementation 
    if (p < n && arr[parent] > arr[p])
    {
        parent = p;
    }
    if (q < n && arr[parent] > arr[q])
    {
        parent = q;
    }
    if (parent != i)
    {
        swap(arr[i], arr[parent]);
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
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
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