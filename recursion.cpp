#include <iostream>
using namespace std;
int fun(int n) {
    int sum = 0;
    if (n == 0)
    {
        return 0;
    }
    else 
    {
    return n + fun(n - 1);
    
    }
    
    
}
int main() {
    int n = 3;
int sum = fun(n);
cout << "sum is: " << sum;
}