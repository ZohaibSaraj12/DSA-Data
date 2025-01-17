#include <iostream>
using namespace std;
void moreUniqueElements(int arr[], int size)
{
    int count[100] = {0};
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    bool found = false;
    cout << "Unique Elements are: ";
    for (int i = 0; i < size; i++)
    {
        if (count[i] == 1)
        {
            cout << i << " ";
            found = true;
        }
    }
    if (!found)
    {
        cout << "No unique Element is Present";
        return;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 3, 4, 6};
    int size = sizeof(arr) / sizeof(int);
    moreUniqueElements(arr, size);
    return 0;
}