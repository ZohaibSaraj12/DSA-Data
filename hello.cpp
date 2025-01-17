#include <iostream>
using namespace std;

int main() {
    int lock = 0;  // Lock initially 0 (free)

    // Infinite loop because lock == 0 is always true and nothing changes
    while (lock == 0);  // Empty loop with semicolon; nothing inside
    lock = 1;

    cout << "Loop exited!" << endl;
    return 0;
}
