#include <iostream>
#include <stack>
using namespace std;

void reverseString(string &str) {
    stack<char> s;
    for (char ch : str)
        s.push(ch);

    for (int i = 0; i < str.length(); i++) {
        str[i] = s.top();
        s.pop();
    }
}

int main() {
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    reverseString(str);

    cout << "Reversed string: " << str << "\n";

    return 0;
}
