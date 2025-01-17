#include <iostream>
using namespace std;
int main() {
    int number = 49;
    int start = 0;
    int end = 48;
    int mid = start + (end - start) / 2;
    int ans = -1;
    
    while (start <= end) {
        mid = start + (end - start) / 2;
    int square = mid * mid;
    if (square == number) {

        ans = mid;
        break;
    }
    else if (square < number) {
        ans = mid;
        start = mid + 1;
    }
    else {
        end = mid - 1;
    }
    }
    cout << ans;
    
    return 0;
}