#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mymutex; // Mutex for synchronization
condition_variable mycondvar; // Condition variable
bool ready = false; // Shared state to signal readiness

void worker() {
    cout << "Worker is waiting for the signal to start working...\n";
    
    // Lock the mutex and wait for the condition variable
    unique_lock<mutex> lock(mymutex);
    mycondvar.wait(lock, [] { return ready; }); // Wait until 'ready' is true

    // Proceed with work after being signaled
    cout << "Worker is now working...\n";
    this_thread::sleep_for(chrono::seconds(2)); // Simulate work
    cout << "Worker finished working!\n";
}

void manager() {
    this_thread::sleep_for(chrono::seconds(1)); // Simulate setup time
    {
        lock_guard<mutex> lock(mymutex);
        ready = true; // Set the 'ready' state to true
    }
    mycondvar.notify_one(); // Notify the worker that it can start working
    cout << "Manager has sent the signal to the worker.\n";
}

int main() {
    thread workerThread(worker);
    thread managerThread(manager);

    workerThread.join();
    managerThread.join();

    return 0;
}
