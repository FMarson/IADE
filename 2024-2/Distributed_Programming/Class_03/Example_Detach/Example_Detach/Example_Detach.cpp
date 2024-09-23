#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void threadFunction() {
    for (int i = 0; i < 5; ++i) {
        cout << "Thread is running: " << i << endl;
        this_thread::sleep_for(chrono::seconds(1)); // Simulates work
    }
}

int main() {
    cout << "Starting the thread..." << endl;

    // Create a thread that executes the threadFunction
    thread myThread(threadFunction);

    // Detach the thread to let it run independently
    myThread.detach();

    // The main program continues to execute
    for (int i = 0; i < 3; ++i) {
        cout << "Main program is running: " << i << endl;
        this_thread::sleep_for(chrono::seconds(1)); // Simulates work
    }

    // Wait a moment before ending the main program
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Main program is finishing..." << endl;

    return 0;
}