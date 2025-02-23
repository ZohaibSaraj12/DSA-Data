#include <iostream>
using namespace std;
void merge(int arr[], int p, int mid, int q)
{
    int n1 = mid - p + 1;
    int n2 = q - mid;

    int l[n1], r[n2];
    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        r[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = p;

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
void mergeSort(int arr[], int p, int q)
{
    if (p < q)
    {
        int mid = p + (q - p) / 2;
        mergeSort(arr, p, mid);
        mergeSort(arr, mid + 1, q);
        merge(arr, p, mid, q);


    }
}

int main()
{
    int arr[5] = {3, 2, 1, 4, 5};

    mergeSort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
       cout << arr[i] << " ";
    }
}