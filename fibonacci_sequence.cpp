#include <iostream>
using namespace std;

// Function to calculate Fibonacci using recursion
int fibonacci(int n) {
    cout << "\ncheck karo dobara agaye ab " << n  << " ye n h" << endl;
    if (n <= 1) {
        cout << "\nif mein agaye" << endl;
        return n;
    }
    return fibonacci(n - 2) + fibonacci(n - 1);
    cout << "function ka end" << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    int arr[n];
    cout << "Fibonacci sequence up to " << n << " terms is: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
        arr[i] = fibonacci(i);
        
    }
    cout << endl;
    cout << "Fibonacci Series is: " << endl;
    for (int i = 0; i < n; i++)
    {
     cout << arr[i] << " ";
    }

    return 0;
}
