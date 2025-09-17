#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(const vector<int>& temperatures) {
    stack<int> s;
    vector<int> result(temperatures.size(), 0);

    for (int i = temperatures.size() - 1; i >= 0; --i) {
        while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top() - i;
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

