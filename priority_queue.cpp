#include <iostream>
#include <queue>
#include <vector>

int main() {
    // Max-heap: Default behavior
    priority_queue<int> maxHeap;

    // Insert elements
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);

    // Display elements in order of priority
    cout << "Max-Heap Elements: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // Get the highest priority element
        maxHeap.pop();                    // Remove the highest priority element
    }
    cout << endl;

    // Min-heap: Use greater<int> to reverse the order
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(15);

    // Display elements in order of priority
    cout << "Min-Heap Elements: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // Get the lowest priority element
        minHeap.pop();                    // Remove the lowest priority element
    }
    cout << endl;

    return 0;
}
