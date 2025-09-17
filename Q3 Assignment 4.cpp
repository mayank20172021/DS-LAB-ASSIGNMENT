#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even!" << endl;
        return;
    }

    queue<int> firstHalf, secondHalf;

    // Split the queue into two halves
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    while (!q.empty()) {
        secondHalf.push(q.front());
        q.pop();
    }

    // Interleave the two halves
    queue<int> resultQueue;
    while (!firstHalf.empty() && !secondHalf.empty()) {
        resultQueue.push(firstHalf.front());
        firstHalf.pop();
        resultQueue.push(secondHalf.front());
        secondHalf.pop();
    }

    cout << "Interleaved Queue: ";
    while (!resultQueue.empty()) {
        cout << resultQueue.front() << " ";
        resultQueue.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    vector<int> arr = {4, 7, 11, 20, 5, 9};

    for (int x : arr) {
        q.push(x);
    }

    interleaveQueue(q);
    return 0;
}

