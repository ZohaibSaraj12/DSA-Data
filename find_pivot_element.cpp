#include <iostream>
using namespace std;
int main() {
    int arr[5] = {3, 8, 10, 17, 1};
    int s = 0; 
    int e = 4;
    int mid = s + (e - s) / 2;
        while (s < e) {
        mid = s + (e - s) / 2;
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
    }
    cout << "Pivot Element's Index is: " << s << endl;
}