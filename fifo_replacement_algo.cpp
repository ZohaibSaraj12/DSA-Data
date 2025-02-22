#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

void fifoPageReplacement(const vector<int>& pages, int capacity) {
    unordered_set<int> pageSet;    // Track pages currently in memory
    queue<int> pageQueue;          // FIFO order of pages
    int pageFaults = 0;

    for (int page : pages) {
        // Page not in memory: Page fault occurs
        if (pageSet.find(page) == pageSet.end()) {
            pageFaults++;

            // Remove the oldest page if memory is full
            if (pageSet.size() == capacity) {
                int oldestPage = pageQueue.front();
                pageQueue.pop();
                pageSet.erase(oldestPage);
            }

            // Add the new page to memory
            pageSet.insert(page);
            pageQueue.push(page);
        }

        // Display current pages in memory
        cout << "Pages in memory: ";
        queue<int> tempQueue = pageQueue;
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
}

int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int capacity = 3;

    cout << "FIFO Page Replacement Simulation\n";
    fifoPageReplacement(pages, capacity);

    return 0;
}
