#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m;
unsigned long long factorial(int n) {
    //lock_guard<mutex> lock(m);
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void computeAndPrintFactorial(int n) {
    lock_guard<mutex> lock(m);
    unsigned long long result = factorial(n);
    cout << "Factorial of " << n << " is " << result << endl;
}

int main() {
    int num1 = 5;
    int num2 = 65;

    thread t1(computeAndPrintFactorial, num1);
    thread t2(computeAndPrintFactorial, num2);

    t1.join();
    t2.join();

    return 0;
}