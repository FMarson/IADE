#include <iostream>
#include <thread>
#include <queue>

using namespace std;
queue<int> resources;
int totalConsumed = 0;
int totalProduced = 0;
bool producionDone = false;

void Producer(){
    for (int i = 0; i < 500; i++){
        resources.push(i);
        totalProduced++;
    }
    producionDone = true;
}

void Consumer(){
    while (!producionDone){
        while (!resources.empty()){
            resources.pop();
            totalConsumed++;
        }
    }
}

int main(){
    thread producer(Producer);
    thread consumer(Consumer);
    producer.join();
    consumer.join();
    cout << "Total Produced: " << totalProduced << endl;
    cout << "Total Consumed: " << totalConsumed << endl;
    cout << "Total Container: " << resources.size() << endl;

    return 0;
}