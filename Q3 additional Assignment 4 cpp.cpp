#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool canSortUsingStack(queue<int>& q) {
    stack<int> s;
    queue<int> result;
    int expected = 1;
    int n = q.size();

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // Push to stack if not expected
        if (front == expected) {
            result.push(front);
            expected++;
        } else {
            // Push to stack
            while (!s.empty() && s.top() == expected) {
                result.push(s.top());
                s.pop();
                expected++;
            }
            s.push(front);
        }
    }

    // Empty stack if possible in order
    while (!s.empty() && s.top() == expected) {
        result.push(s.top());
        s.pop();
        expected++;
    }

    return expected == n + 1;
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << (canSortUsingStack(q) ? "Yes" : "No") << endl;
    return 0;
}

