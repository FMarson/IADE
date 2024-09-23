#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex MyMutex;

void myPrint(const string& name){
    lock_guard<mutex> lock(MyMutex);
    cout << name << " is starting..\n";
    for(int i=0;i<=15;i++){
        cout << name << ": " << i << endl;
    }
    //lock_guard<mutex> unlock(MyMutex);
}

int main() {

    thread myThread(myPrint, "T1");
    thread otherThread(myPrint, "T2");
    myThread.join();
    otherThread.join();
    
    cout << "All threads are done!\n";
    return 0;
}