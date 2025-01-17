// mean of individual Series in c++
#include <iostream>
using namespace std;
int main() {
    int arr[5] = {3, 2, 1, 5, 4};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + arr[i];
    }
    float x = sum / 5.0;
    cout  << "mean is : " << x << endl;
    return 0;
}