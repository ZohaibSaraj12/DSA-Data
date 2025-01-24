#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;


    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
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
        
       
       
        int temp = arr[0];
        arr[0] = arr[size];
        arr[size] = temp;
        size = size - 1;
        cout << "\nsize after decrement" << size << " "  << endl;
        // This is Wrong if not size + 1 in 2nd argument of heapify
        // heapify(arr, size, 0);
        // Now on next line is correct
        heapify(arr, size + 1, 0);
    }
}
int main()
{
    int arr[6] = {10, 70, 30, 50, 20, 3};
    heapSort(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " "; 
    }
}
