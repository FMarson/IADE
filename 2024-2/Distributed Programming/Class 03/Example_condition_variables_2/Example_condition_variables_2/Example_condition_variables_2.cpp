#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <vector>

using namespace std;

mutex mymutex; // Mutex for synchronization
condition_variable mycondvar; // Condition variable
bool ready = false; // Shared state to signal readiness

void worker(int id) {
    {
        unique_lock<mutex> lock(mymutex);
        cout << "Worker " << id << " is waiting for the signal to start working...\n";
        while (!ready) { // Use while loop to avoid spurious wakeups
            mycondvar.wait(lock); // Wait until 'ready' is true
        }
    }

    // Proceed with work after being signaled
    mymutex.lock();
    cout << "Worker " << id << " is now working...\n";
    mymutex.unlock();
    this_thread::sleep_for(chrono::seconds(1)); // Simulate work
    mymutex.lock();
    cout << "Worker " << id << " finished working!\n";
    mymutex.unlock();
}

void manager() {
    this_thread::sleep_for(chrono::seconds(1)); // Simulate setup time
    {
        lock_guard<mutex> lock(mymutex);
        ready = true; // Set the 'ready' state to true
    }
    cout << "Manager has sent the signal to all workers.\n";
    mycondvar.notify_all(); // Notify all workers that they can start working
    
}

int main() {
    const int numWorkers = 10;
    vector<thread> workers;

    // Create and start worker threads
    for (int i = 0; i < numWorkers; ++i) {
        workers.emplace_back(worker, i + 1); // Pass worker ID starting from 1
    }

    thread managerThread(manager);

    // Wait for all workers and the manager to finish
    for (auto& w : workers) {
        w.join();
    }
    managerThread.join();

    return 0;
}
