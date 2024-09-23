#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex mtx;
//lock_guard<mutex> lock(mtx);
//lock_guard<mutex> unlock(mtx);

void print_numbers(const std::string& thread_id) {
    lock_guard<mutex> lock(mtx); 
    cout << "Entering " << thread_id << endl;
    for (int i = 0; i < 5; ++i) {
        cout << thread_id << ": " << i << endl;
    }
    lock_guard<mutex> unlock(mtx);
}

int main() {
    thread t1(print_numbers, "Thread 1");
    thread t2(print_numbers, "Thread 2");
    thread t3(print_numbers, "Thread 3");
    thread t4(print_numbers, "Thread 4");
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << "All threads finished" << endl;
    return 0;
}
