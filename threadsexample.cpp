#include <iostream>
#include <thread>
#include <chrono>

// Function 1: Perform some task
void task1() {
    for (int i = 0; i < 10; ++i) {
        cout << "Task 1 is running...\n";
        this_thread::sleep_for(chrono::milliseconds(500)); // Simulate work
    }
}

// Function 2: Perform another task
void task2() {
    for (int i = 0; i < 10; ++i) {
        cout << "Task 2 is running...\n";
        this_thread::sleep_for(chrono::milliseconds(500)); // Simulate work
    }
}

// Function 3: Perform a CPU-intensive task
void cpuIntensiveTask() {
    cout << "CPU-intensive task is starting...\n";
    long long sum = 0;
    for (long long i = 0; i < 1e8; ++i) {
        sum += i; // Simulate heavy computation
    }
    cout << "CPU-intensive task finished. Sum = " << sum << "\n";
}

int main() {
    // Creating threads
    thread thread1(task1);
    thread thread2(task2);
    thread thread3(cpuIntensiveTask);

    // Wait for all threads to finish
    thread1.join();
    thread2.join();
    thread3.join();

    cout << "All tasks completed.\n";

    return 0;
}
