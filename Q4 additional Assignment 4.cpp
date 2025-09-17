#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int countStudentsUnableToEat(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students)
        q.push(s);

    int index = 0;
    int rotations = 0;
    int n = students.size();

    while (!q.empty() && rotations < q.size()) {
        if (q.front() == sandwiches[index]) {
            q.pop();
            index++;
            rotations = 0;
        } else {
            q.push(q.front());
            q.pop();
            rotations++;
        }
    }

    return q.size();
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    cout << countStudentsUnableToEat(students, sandwiches) << endl;
    return 0;
}

