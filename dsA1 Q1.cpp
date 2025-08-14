#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX], n = 0;

void createArray() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void displayArray() {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void insertElement() {
    int pos, val;
    cin >> pos >> val;
    for (int i = n; i >= pos; i--) arr[i] = arr[i - 1];
    arr[pos - 1] = val;
    n++;
}

void deleteElement() {
    int pos;
    cin >> pos;
    for (int i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

void linearSearch() {
    int key, found = 0;
    cin >> key;
    for (int i = 0; i < n; i++)
        if (arr[i] == key) {
            cout << i + 1 << endl;
            found = 1;
        }
    if (!found) cout << "Not found\n";
}

int main() {
    int ch;
    do {
        cin >> ch;
        if (ch == 1) createArray();
        else if (ch == 2) displayArray();
        else if (ch == 3) insertElement();
        else if (ch == 4) deleteElement();
        else if (ch == 5) linearSearch();
    } while (ch != 6);
}
