#include <iostream>
using namespace std;
// 4 3 1 2 5 
void merge(int arr[], int p, int mid, int q)
{
    // p = 0     // mid = 0      // q = 1
    int n1 = mid - p + 1;    //  n1 = 0 - 0 + 1 = 1
    int n2 = q - mid;      //   n2 = 1 - 0 = 1

    int l[n1], r[n2];         // l[1] and r[1]
    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[p + i]; // l[0] = arr[0] = 4
        // Correctly copy elements to p array
    }
    for (int j = 0; j < n2; j++)
    {
        r[j] = arr[mid + 1 + j];  // r[0] = arr[1] = 3
        // Correctly copy elements to q array
    }

    int i = 0, j = 0, k = p; 
    // Initialize k to 'p'
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

void mergeSort(int arr[], int p, int q)
{

    cout << "Ye function ka shrooh h recrusion nahin hoi filhaaal" << " p " << p << " q " << q << " " << endl << endl;

    if (p < q)
    {
        int mid = p + (q - p) / 2;
        cout << "mid horaha haye dekho " << mid << endl << endl;
        cout << "ye sab dekh lo p part k liye " << "mergesort(p = " << p << ", mid = " << mid << ")" << " p " << p << " mid " << mid << " " << "q " << q << endl
             << endl;
        mergeSort(arr, p, mid);
        cout << "fucntion k liye " << " mid to haye " << mid << " mid + 1 ye haye " << mid + 1 << endl;
        cout << "ye sab dekh lo q part k liye " << "mergesort(mid + 1 = " << mid + 1 << ",q =  " << q << ")" << " p " << p << " mid " << mid << " q " << q << " " << endl
             << endl;
        mergeSort(arr, mid + 1, q);
        cout << "merge horaha haye" << " p " << p << " mid " << mid << " q " << q << " " << endl
             << endl;

        merge(arr, p, mid, q);
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
