#include <iostream>
using namespace std;

class Heap {
    public:
    int size;
    int arr[100];

    Heap()
    {
        size = 0;
    }
    void input(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parent = index / 2;
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
        cout << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Heap h;
    h.input(50);
    h.input(55);
    h.input(53);
    h.input(52);
    h.input(54);

    h.print();

    
    return 0;
}