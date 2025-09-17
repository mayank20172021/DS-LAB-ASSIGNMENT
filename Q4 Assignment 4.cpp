#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

void firstNonRepeating(const string& str) {
    unordered_map<char, int> count;
    queue<char> q;

    for (char ch : str) {
        q.push(ch);
        count[ch]++;

        // Remove elements from queue that are repeating
        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input = "aabcc";
    firstNonRepeating(input);
    return 0;
}

