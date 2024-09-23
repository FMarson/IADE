#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

int counter = 0; // Non-thread-safe variable
atomic<int> aCounter(0); // Thread-safe variable

void countNumbers(){
    for(int i = 0; i < 10000; i++){
        ++counter; // Non-atomic access
        ++aCounter; // Atomic access
    }
}

int main() {
    const int numThreads = 1000; // Number of threads
    vector<thread> threads; // Vector to store threads

    // Create and start the threads
    for(int i = 0; i < numThreads; i++) {
        threads.emplace_back(countNumbers);
    }

    // Wait for all threads to finish
    for(auto& t : threads) {
        t.join();
    }

    // Display the results
    cout << "Final value of counter (non-atomic): " << counter << endl;
    cout << "Final value of aCounter (atomic): " << aCounter.load() << endl;

    return 0;
}
