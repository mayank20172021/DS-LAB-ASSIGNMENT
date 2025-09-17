#include <iostream>
#include <queue>
using namespace std;

void sortQueue(queue<int>& q) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        int min_val = INT_MAX;
        int min_index = -1;
        int current_size = q.size();

        // Find minimum in queue
        for (int j = 0; j < current_size; j++) {
            int curr = q.front();
            q.pop();
            if (curr < min_val && j <= size - i - 1) {
                min_val = curr;
                min_index = j;
            }
            q.push(curr);
        }

        // Move elements, skipping the min element once
        for (int j = 0; j < current_size; j++) {
            int curr = q.front();
            q.pop();
            if (j != min_index)
                q.push(curr);
        }

        // Add minimum element at the end (sorted position)
        q.push(min_val);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

