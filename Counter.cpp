#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <sstream> // For thread-local string accumulation

// Mutex and condition variable for synchronization between threads
std::mutex mtx; // Protects shared resources
std::condition_variable cv; // Used to signal between threads
bool countUpDone = false; // Flag to indicate when the countUp thread has finished

// Thread function to count up to 20
void countUp() {
    std::ostringstream output; // Thread-local buffer to accumulate output
    for (int i = 1; i <= 20; ++i) {
        output << "Thread 1 (Count Up): " << i << "\n"; // Append each number to the buffer
    }

    // Output all at once to minimize mutex usage
    {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex to protect shared resources
        std::cout << output.str(); // Write the accumulated output to std::cout
        countUpDone = true; // Set the flag to indicate that countUp is complete
    }
    cv.notify_one(); // Notify the other thread waiting on the condition variable
}

// Thread function to count down to 0
void countDown() {
    std::unique_lock<std::mutex> lock(mtx); // Lock the mutex to wait on the condition variable
    cv.wait(lock, [] { return countUpDone; }); // Wait until the countUp thread signals completion

    std::ostringstream output; // Thread-local buffer to accumulate output
    for (int i = 20; i >= 0; --i) {
        output << "Thread 2 (Count Down): " << i << "\n"; // Append each number to the buffer
    }

    // Output all at once
    std::cout << output.str(); // Write the accumulated output to std::cout
}

int main() {
    std::thread thread1(countUp); // Create thread1 to execute countUp
    std::thread thread2(countDown); // Create thread2 to execute countDown

    thread1.join(); // Wait for thread1 to finish
    thread2.join(); // Wait for thread2 to finish

    return 0; // Exit the program
}
