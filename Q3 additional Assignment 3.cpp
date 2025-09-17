#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& arr) {
    stack<int> s;
    vector<int> result(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top();
        }
        s.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(arr);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

