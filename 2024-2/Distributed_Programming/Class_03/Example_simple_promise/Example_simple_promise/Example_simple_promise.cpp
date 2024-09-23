#include <iostream>
#include <future>

using namespace std;

void task(promise<int> prom) {
    prom.set_value(42); // Sets the promised value
}

int main() {
    promise<int> prom; // Creates a promise
    future<int> future = prom.get_future(); // Gets the associated future

    thread t(task, move(prom)); // Starts the task in a new thread
    
    cout << "Waiting for the result...\n";
    cout << "Result: " << future.get() << '\n'; // Waits and obtains the value
    t.join(); // Waits for the thread to finish
    return 0;
}
