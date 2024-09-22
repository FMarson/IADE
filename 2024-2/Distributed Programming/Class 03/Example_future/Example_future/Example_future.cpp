#include <iostream>
#include <future>
#include <vector>

// Function to perform counting
int count() {
    int counter = 0;
    for (int i = 0; i < 10000; i++) {
        ++counter;
    }
    return counter;
}

int main() {
    std::vector<std::future<int>> futures; // Vector to store futures
    const int numTasks = 1000;
    int result = 0;

    // Launch asynchronous tasks
    for (int i = 0; i < numTasks; i++) {
        // Store the future returned by async in the futures vector
        futures.emplace_back(std::async(std::launch::async, count));
    }

    // Wait for all futures to complete and accumulate results
    for (auto& fut : futures) {
        result += fut.get(); // This will block until the future is ready and accumulate the result
    }

    // Display the results
    std::cout << "Final value of result: " << result << std::endl;

    return 0;
}

