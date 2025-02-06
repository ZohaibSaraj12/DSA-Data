#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        size = 0;
    }
    void insert(int value)
    {
        int index = size;  
        arr[index] = value;   
        size++;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void heapify(int arr[], int n, int i)
    {
        int parent = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < n && arr[parent] < arr[left])
        {
            parent = left;
        }
        if (right < n && arr[parent] < arr[right])
        {
            parent = right;
        }

        if (parent != i)
        {
            swap(arr[parent], arr[i]);
            heapify(arr, n, parent);
        }
    }
    void deleteE()
    {
        if (size == 0)
        {
            cout << "Nothing To Delete Wan Pary";
            return;
        }

        arr[0] = arr[size - 1];
        
        size--;
        int i = 0;
        heapify(arr, size, i);
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
main()
{
    Heap h;
    h.insert(70);
    h.insert(60);
    h.insert(50);
    h.insert(1);
    h.insert(5);

    cout << "Printing array : " << endl;

    h.print();
    h.deleteE();

    cout << "After Deletion Printing array : " << endl;

    h.print();
}