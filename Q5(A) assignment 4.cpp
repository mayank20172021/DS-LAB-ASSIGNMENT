#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        // Leave one element in q1 and push others to q2
        while (q1.size() > 1) {
            int front = q1.front();
            q1.pop();
            q2.push(front);
        }
        // Pop the last element
        cout << "Popped: " << q1.front() << endl;
        q1.pop();

        // Swap queues
        swap(q1, q2);
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        while (q1.size() > 1) {
            int front = q1.front();
            q1.pop();
            q2.push(front);
        }
        int topElement = q1.front();
        q1.pop();
        q2.push(topElement);  // push it back to q2

        swap(q1, q2);
        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    s.pop();
    s.pop();

    if (s.empty())
        cout << "Stack is empty now.\n";

    return 0;
}

