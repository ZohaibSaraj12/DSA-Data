#include <iostream>
using namespace std;
void reverse(int arr[], int n)
{
    int start = 0; 
    int end = n - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int main()
{
    int arr[5] = {5, 2, 1, 3, 8};

    reverse(arr, 5);

    cout << "Reversed Array" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}