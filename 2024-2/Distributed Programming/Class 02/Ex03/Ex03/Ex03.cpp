#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
double balance = 0.0;

void deposit(double amount) {
    lock_guard<mutex> lock(mtx);
    balance += amount;
    cout << "Deposited " << amount << ", new balance: " << balance << endl;
}

void withdraw(double amount) {
    lock_guard<mutex> lock(mtx);
    if (balance >= amount) {
        balance -= amount;
        cout << "Withdrew " << amount << ", new balance: " << balance << endl;
    } else {
        cout << "Insufficient funds to withdraw " << amount << ", current balance: " << balance << endl;
    }
}

int main() {
    thread t1(deposit, 500);
    thread t2(withdraw, 200);

    t1.join();
    t2.join();

    return 0;
}
