#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nearestSmallerElement(const vector<int>& A) {
    stack<int> s;
    vector<int> result;

    for (int num : A) {
        while (!s.empty() && s.top() >= num) {
            s.pop();
        }
        if (s.empty()) {
            result.push_back(-1);
        } else {
            result.push_back(s.top());
        }
        s.push(num);
    }

    return result;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> result = nearestSmallerElement(A);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

