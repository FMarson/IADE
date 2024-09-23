#include <iostream>
#include <future>
#include <thread>

using namespace std;

void task(int x, promise<int> prom) {
    prom.set_value(x * 2);
}

int main() {
    promise<int> prom;
    future<int> future = prom.get_future();

    packaged_task<void()> pt(bind(task, 10, move(prom)));
    thread t(move(pt)); // Executes the packaged_task in a new thread
    
    cout << "Result: " << future.get() << '\n'; // Waits for the result
    t.join(); // Waits for the thread to finish
    return 0;
}
