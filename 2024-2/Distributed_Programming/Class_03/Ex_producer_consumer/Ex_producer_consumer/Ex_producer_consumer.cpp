#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable>

using namespace std;

queue<int> resources; // Queue to hold produced items
int totalConsumed = 0; // Total number of items consumed
int totalProduced = 0; // Total number of items produced
bool productionDone = false; // Flag to indicate if production is done

mutex mtx; // Mutex for protecting shared resources
condition_variable cv; // Condition variable for signaling

void Producer() {
    for (int i = 0; i < 500000; i++) {
        {
            lock_guard<mutex> lock(mtx); // Lock the mutex for thread safety
            resources.push(i); // Produce an item
            totalProduced++; // Increment total produced
        }
    }
    {
        lock_guard<mutex> lock(mtx);
        productionDone = true; // Indicate that production is done
    }
    cv.notify_all(); // Notify all consumers that production is done
}

void Consumer()
{
    while (!resources.empty() || !productionDone) {
        int item;
        {
            unique_lock<mutex> lock(mtx); // Lock the mutex
            cv.wait(lock, [] { return !resources.empty() || !productionDone; }); // Wait for items or production to complete
            
            // Exit if production is done and there are no more items
            if (resources.empty() && productionDone) {
                return; 
            }

            // Consume an item
            item = resources.front();
            resources.pop();
            totalConsumed++; // Increment total consumed
        }
    }
}

int main() {
    thread producer(Producer); // Create producer thread
    thread consumer(Consumer); // Create consumer thread

    producer.join(); // Wait for producer to finish
    consumer.join(); // Wait for consumer to finish

    cout << "Total Produced: " << totalProduced << endl;
    cout << "Total Consumed: " << totalConsumed << endl;
    cout << "Total Container: " << resources.size() << endl;

    return 0;
}
