#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int mymatrix[5][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};

void sumRow(int rowIndex, int& result) {
    result = 0;
    for (int i = 0; i < 5; ++i) {
        result += mymatrix[rowIndex][i];
    }
}

int main() {
    vector<thread> threads;
    int results[5] = {0};

    for (int i = 0; i < 5; ++i) {
        threads.push_back(thread(sumRow, i, ref(results[i])));
    }

    for (int i = 0; i < 5; ++i) {
        threads[i].join();
    }

    for (int i = 0; i < 5; ++i) {
        cout << "Sum of row " << i << " is " << results[i] << endl;
    }

    return 0;
}
