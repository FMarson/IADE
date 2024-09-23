#include <iostream>
#include <future>
#include <chrono>

using namespace std;

int task(int x) {
    this_thread::sleep_for(chrono::seconds(2)); // Simulates work
    return x * 2;
}

int main() {
    future<int> result = async(launch::async, task, 10);
    
    cout << "Doing something while waiting...\n";
    
    int value = result.get(); // Waits until the task is completed
    cout << "Result: " << value << '\n'; // Prints the result
    return 0;
}
