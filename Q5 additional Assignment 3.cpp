#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool canBeSorted(vector<int>& A) {
    stack<int> S;
    vector<int> B;

    while (!A.empty()) {
        int current = A.front();
        A.erase(A.begin());

        // Move elements from stack to B if they are in order
        while (!S.empty() && (S.top() == B.size() + 1)) {
            B.push_back(S.top());
            S.pop();
        }

        if (!S.empty() && S.top() < current) {
            return false;
        }
        S.push(current);
    }

    // Move any remaining elements from stack to B
    while (!S.empty()) {
        B.push_back(S.top());
        S.pop();
    }

    // Check if B is sorted
    for (int i = 1; i < B.size(); ++i) {
        if (B[i] < B[i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> A = {4, 3, 2, 1};
    if (canBeSorted(A)) {
        cout << "Yes, array can be sorted using stack operations." << endl;
    } else {
        cout << "No, array cannot be sorted using stack operations." << endl;
    }

    return 0;
}

