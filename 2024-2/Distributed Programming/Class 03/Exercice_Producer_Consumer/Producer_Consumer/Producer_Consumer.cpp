#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable>

using namespace std;

queue<int> resources;
int totalConsumed = 0;
int totalProduced = 0;
bool productionDone = false;

mutex mtx; // Mutex for synchronization
condition_variable cv; // Condition variable for signaling

void Producer() {
    for (int i = 0; i < 50000; i++) {
        {
            lock_guard<mutex> lock(mtx); // Lock the mutex
            resources.push(i); // Produce an item
            totalProduced++;
        }
        cv.notify_one(); // Notify a waiting consumer that an item is available
    }
    {
        lock_guard<mutex> lock(mtx);
        productionDone = true; // Indicate that production is done
    }
    cv.notify_one(); // Notify consumer in case it is waiting
}

void Consumer() {
    while (!productionDone || !resources.empty()) {
        int item;
        {
            unique_lock<mutex> lock(mtx); // Lock the mutex
            cv.wait(lock, [] { return !resources.empty() || productionDone; }); // Wait for items or production to complete

            // Consume an item
            item = resources.front();
            resources.pop();
            totalConsumed++;
        }
    }
}

int main() {
    thread producer(Producer);
    thread consumer(Consumer);

    producer.join();
    consumer.join();

    cout << "Total Produced: " << totalProduced << endl;
    cout << "Total Consumed: " << totalConsumed << endl;
    cout << "Total Container: " << resources.size() << endl;

    return 0;
}
