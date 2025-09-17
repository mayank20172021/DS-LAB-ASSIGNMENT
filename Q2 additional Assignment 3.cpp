#include <iostream>
#include <stack>
using namespace std;

class StackWithMin {
public:
    void push(int value) {
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
        mainStack.push(value);
    }

    void pop() {
        if (mainStack.empty()) return;
        int value = mainStack.top();
        mainStack.pop();
        if (value == minStack.top()) {
            minStack.pop();
        }
    }

    int getMin() {
        if (minStack.empty()) return -1;
        return minStack.top();
    }

private:
    stack<int> mainStack;
    stack<int> minStack;
};

int main() {
    StackWithMin s;
    s.push(5);
    s.push(3);
    s.push(7);
    cout << "Minimum: " << s.getMin() << endl;
    s.pop();
    cout << "Minimum: " << s.getMin() << endl;

    return 0;
}

