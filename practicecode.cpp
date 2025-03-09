// All sorting practice

// Bubble Sort
/*#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {3, 2, 5, 1, 4};
    const int n = 5;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i -1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}*/

// selection Sort

/*#include <iostream>
#include <vector>
using namespace std;
int main()
{
   vector<int> arr = {3, 2, 5, 1, 4};


    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }


    for (const auto& num : arr)
    {
        cout << num << " ";
    }

}*/

// insertion sort
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
   vector<int> arr = {3, 2, 5, 1, 4};

   for (int i = 1; i < arr.size(); i++)
   {
    int key = arr[i];
    // masla
    int j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
   }
   for (const auto& num : arr)
   {
    cout << num << " ";
   }

}
*/

// quick sort
/*
#include <iostream>
#include <vector>
using namespace std;
int partitionGame(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int p = low + 1;
    int q = high;

    while(p <= q)
    {
        if (p <= q && arr[p] <= pivot)
        {
            p++;
        }
        if (p <= q && arr[q] > pivot)
        {
            q--;
        }

        if (p < q)
        {
            swap(arr[p], arr[q]);
        }
    }
    swap(arr[q], arr[low]);
    return q;

}
void quickSort(vector<int>& arr, int left, int right)
{
if (left < right)
{
    int pivotIndex = partitionGame(arr, left, right);
    quickSort(arr, 0, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

}
int main()
{
   vector<int> arr = {3, 2, 5, 1, 4};

   // masla
   quickSort(arr, 0, arr.size() - 1);
   for (const auto& num : arr)
   {
    cout << num << " ";
   }

}

*/

// merge sort
/*
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int l[n1], r[n2];

    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = arr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = left;

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
    while (j < n1)
    {
        arr[k++] = r[j++];
    }
}
void mergeSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        mergeSort(arr, 0, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    vector<int> arr = {3, 2, 5, 1, 4};

   // masla
   mergeSort(arr, 0, arr.size() - 1);
   for (const auto& num : arr)
   {
    cout << num << " ";
   }
}
*/
// shell sort
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{

   vector<int> arr = {3, 2, 5, 1, 4};
   int temp = 0;
   for (int gap = arr.size() / 2; gap > 0; gap /= 2)
   {
    for (int i = gap; i < arr.size(); i++)
    {
        temp = arr[i];
        int j = i;

        while (j >= gap && arr[j - gap] > temp)
        {
            arr[j] = arr[j - gap];
            j = j - gap;
        }
        arr[j] = temp;

    }
   }

   for (const auto& num : arr)
   {
    cout << num << " ";
   }

}
*/

// bucketSort
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
   vector<float> arr = {0.2, 0.5, 0.92, 0.45};
   const int bucketCount = 10;
   vector<float> bucketArray[bucketCount];


   for (const auto& num : arr)
   {
    int bucketIndex = num * bucketCount;
    bucketArray[bucketIndex].push_back(num);
   }

   for (int i = 0; i < bucketCount; i++)
   {
    sort(bucketArray[i].begin(), bucketArray[i].end());
   }

   int index = 0;

   for (int i = 0; i < bucketCount; i++)
   {
    for (int j = 0; j < bucketArray[i].size(); i++)
    {
        arr[index++] = bucketArray[i][j];
    }
   }
   for (const auto& num : arr)
   {
    cout << num << " ";
   }

}
*/

// count sort
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
   vector<int> arr = {3, 2, 5, 1, 4};
   int minValue = *min_element(arr.begin(), arr.end());
   int maxValue = *max_element(arr.begin(), arr.end());
   int range = maxValue - minValue + 1;
   vector<int> count(range, 0);
   vector<int> output (arr.size());

   for(const auto& num : arr)
   {
    count[num - minValue]++;
   }

   for (int i = 1; i < range; i++)
   {
    count[i] = count[i] + count[i - 1];
   }

   for (int i = 0; i < arr.size(); i++)
   {
    output[count[arr[i] - minValue] - 1] = arr[i];
    count[arr[i] - minValue]--;
   }
   for (int i = 0; i < arr.size(); i++)
   {
    arr[i] = output[i];
   }
   for (const auto& num : arr)
   {
    cout << num << " ";
   }

}
*/

// radix sort
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr = {3, 2, 5, 1, 4};

    int maxValue = *max_element(arr.begin(), arr.end());

    vector<int> count(10, 0);
    vector<int> output(arr.size());
    for (int exp = 1; (maxValue / exp) > 0; exp *= 10)
    {
        for (const auto &num : arr)
        {
            int digit = (num / exp) % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] = count[i] + count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = output[i];
        }
    }
    for (const auto &num : arr)
    {
        cout << num << " ";
    }
}
    */

// heap sort
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void heapify(vector<int>& arr, int n, int i)
{
    int parent = i;
    int lc = i * 2 + 1;
    int rc = i * 2 + 2;
    
    if (lc < n && arr[parent] > arr[lc])
    {
        parent = lc;
    }
    if (rc < n && arr[parent] > arr[rc])
    {
        parent = rc;
    }

    if (parent != i)
    {
        swap(arr[i], arr[parent]);
        heapify(arr, n, parent);
    }
} 
void heapSort(vector<int>& arr, int n)
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
    vector<int> arr = {3, 2, 5, 1, 4};
    heapSort(arr, arr.size());
    
    for (const auto &num : arr)
    {
        cout << num << " ";
    }
}*/

// merge again
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int l[n1], r[n2];

    for (int i = 0; i < n1; i++)
    {
    l[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
    r[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = left;
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
void mergeSort(vector<int>& arr, int low, int high)
{
   if (low < high)
   {
    int mid = low + (high - low) / 2;
    mergeSort(arr, 0, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr,low, mid, high);
   }
}
int main()
{
    vector<int> arr = {3, 2, 5, 1, 4};
    mergeSort(arr, 0, arr.size() - 1);
    for (const auto& num : arr)
    {
        cout << num << " ";
    }
}*/

//shell again
 /*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr = {3, 2, 5, 1, 4};
    int temp = 0;
    for (int gap = arr.size() / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < arr.size(); i++)
        {
            temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
    for (const auto &num : arr)
    {
        cout << num << " ";
    }
}*/

//bucket sort again
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<float> arr = {0.4, 0.23, 0.12, 0.13, 0.45, 0.98};
    const int bucketCount = 10;
    vector<float> bucketArray[bucketCount];


    for (const auto& num : arr)
    {
        int bucketIndex = num * bucketCount;
        bucketArray[bucketIndex].push_back(num);

    }
    for (int i = 0; i < bucketCount; i++)
    {
        sort(bucketArray[i].begin(), bucketArray[i].end());
    }
    int index = 0;
    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 0; j < bucketArray[i].size(); j++)
        {
            arr[index++] = bucketArray[i][j];
        }
    }

    
    for (const auto &num : arr)
    {
        cout << num << " ";
    }
}
*/

// radix sort again
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr = {3, 1, 4, 6, 77, 901};
    int m = *max_element(arr.begin(), arr.end());
    vector<int> output(arr.size());
    for (int exp = 1; (m / exp) > 0; exp *= 10)
    {
        vector<int> count(10, 0);
        for (const auto& num : arr)
        {
            int digit = (num / exp) % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] = count[i] + count[i - 1];
        }
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = output[i];
        }
    }
    
    for (const auto &num : arr)
    {
        cout << num << " ";
    }
}
*/

// count sort again

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr = {4, 3, 2, 1, 5};
    vector<int> output(arr.size());
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    vector<int> count(range, 0);
    for (const auto &num : arr)
    {
        count[num - min]++;
    }
    for (int i = 1; i < range; i++)
    {
        count[i] = count[i] + count[i - 1];

    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = output[i];
    }
    for (const auto& num : arr)
    {
        cout << num << " ";
    }
}