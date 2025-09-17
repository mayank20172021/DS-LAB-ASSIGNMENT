#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, size, capacity;

public:
    Queue(int c) {
        capacity = c;
        arr = new int[c];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Enqueue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
        } else {
            rear = (rear + 1) % capacity;
            arr[rear] = value;
            size++;
            cout << value << " enqueued!" << endl;
        }
    }

    // Dequeue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << arr[front] << " dequeued!" << endl;
            front = (front + 1) % capacity;
            size--;
        }
    }

    // Is Empty
    bool isEmpty() {
        return size == 0;
    }

    // Is Full
    bool isFull() {
        return size == capacity;
    }

    // Display
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            int i = front;
            for (int count = 0; count < size; count++) {
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << endl;
        }
    }

    // Peek
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() {
    int capacity;
    cout << "Enter queue capacity: ";
    cin >> capacity;
    Queue q(capacity);
    
    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if Queue is Empty\n";
        cout << "4. Check if Queue is Full\n";
        cout << "5. Display Queue\n";
        cout << "6. Peek Front\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full" : "Queue is not full") << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 7:
                cout << "Exiting program!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}

