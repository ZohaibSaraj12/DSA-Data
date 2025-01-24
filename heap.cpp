#include <iostream>
using namespace std;
class Heap {
    public:
    int arr[100];
    int size;
    Heap()
    {
        size = 0;
        
    }
    void insert(int value)
    {
        size = size + 1;
        int index = size - 1;
        arr[index] = value;

        while(index > 0)
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
    h.insert(10);
    h.insert(20);
    h.insert(40);
    h.insert(1);
    h.insert(5);

    cout << "Printing Array" << endl;
    h.print();

}