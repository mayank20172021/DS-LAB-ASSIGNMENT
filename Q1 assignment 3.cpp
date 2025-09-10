#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() { return top == MAX - 1; }

    bool isEmpty() { return top == -1; }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. IsEmpty\n6. IsFull\n7. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                val = s.pop();
                if (val != -1)
                    cout << "Popped: " << val << "\n";
                break;
            case 3:
                val = s.peek();
                if (val != -1)
                    cout << "Top element: " << val << "\n";
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 6:
                cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n");
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
