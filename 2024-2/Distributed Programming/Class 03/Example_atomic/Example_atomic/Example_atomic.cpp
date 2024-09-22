#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

int counter = 0; // Non-thread-safe variable
std::atomic<int> aCounter(0); // Thread-safe variable

void count(){
    for(int i = 0; i < 10000; i++){
        ++counter; // Non-atomic access
        ++aCounter; // Atomic access
    }
}

int main() {
    const int numThreads = 1000; // Number of threads
    std::vector<std::thread> threads; // Vector to store threads

    // Create and start the threads
    for(int i = 0; i < numThreads; i++) {
        threads.emplace_back(count);
    }

    // Wait for all threads to finish
    for(auto& t : threads) {
        t.join();
    }

    // Display the results
    std::cout << "Final value of counter (non-atomic): " << counter << std::endl;
    std::cout << "Final value of aCounter (atomic): " << aCounter.load() << std::endl;

    return 0;
}