#include <iostream>
using namespace std;
// 4 3 1 2 5 
void merge(int arr[], int left, int mid, int right)
{
    // left = 0     // mid = 0      // right = 1
    int n1 = mid - left + 1;    //  n1 = 0 - 0 + 1 = 1
    int n2 = right - mid;      //   n2 = 1 - 0 = 1

    int l[n1], r[n2];         // l[1] and r[1]
    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[left + i]; // l[0] = arr[0] = 4
        // Correctly copy elements to left array
    }
    for (int j = 0; j < n2; j++)
    {
        r[j] = arr[mid + 1 + j];  // r[0] = arr[1] = 3
        // Correctly copy elements to right array
    }

    int i = 0, j = 0, k = left; 
    // Initialize k to 'left'
    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            arr[k++] = l[i++];
        }
        else
        {
            arr[k++] = r[j++];  //arr[0] = r[0] = 3 
        }
    }

    while (i < n1)
    {                  
        arr[k++] = l[i++]; // arr[1] = l[0] = 4
    }
    while (j < n2)
    {
        arr[k++] = r[j++];
    }
}

void mergeSort(int arr[], int left, int right)
{

    cout << "Ye function ka shrooh h recrusion nahin hoi filhaaal" << " left " << left << " right " << right << " " << endl << endl;

    if (left < right)
    {
        int mid = left + (right - left) / 2;
        cout << "mid horaha haye dekho " << mid << endl << endl;
        cout << "ye sab dekh lo left part k liye " << "mergesort(left = " << left << ", mid = " << mid << ")" << " left " << left << " mid " << mid << " " << "right " << right << endl
             << endl;
        mergeSort(arr, left, mid);
        cout << "fucntion k liye " << " mid to haye " << mid << " mid + 1 ye haye " << mid + 1 << endl;
        cout << "ye sab dekh lo right part k liye " << "mergesort(mid + 1 = " << mid + 1 << ",right =  " << right << ")" << " left " << left << " mid " << mid << " right " << right << " " << endl
             << endl;
        mergeSort(arr, mid + 1, right);
        cout << "merge horaha haye" << " left " << left << " mid " << mid << " right " << right << " " << endl
             << endl;

        merge(arr, left, mid, right);
        cout << "Dobara control mil gaya wohooo" << endl;
    }
}

int main()
{
    int arr[5] = {4, 3, 1, 2, 5};
    mergeSort(arr, 0, 4); // Use the correct array bounds

    cout << "Sorted array is: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}
