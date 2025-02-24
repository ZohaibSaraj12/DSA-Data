#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int parent = i;
    int lc = i * 2 + 1;
    int rc = i * 2 + 2;

    if (lc < n && arr[parent] > arr[lc])
    {
        parent = lc;
    }
    if (rc < n &&  arr[parent] > arr[rc])
    {
        parent = rc;
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
    while (size > 0)
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
    int arr[5] = {3, 2, 1, 5, 4};
    heapSort(arr, 5);


    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}