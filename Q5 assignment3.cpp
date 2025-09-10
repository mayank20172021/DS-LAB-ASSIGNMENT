#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> s;

    for (char ch : postfix) {
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch(ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }

    return s.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single digit operands): ";
    getline(cin, postfix);

    cout << "Evaluated result: " << evaluatePostfix(postfix) << "\n";

    return 0;
}
