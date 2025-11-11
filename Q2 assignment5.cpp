#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void countAndDelete(Node*& head, int key) {
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            count++;
            if (prev == NULL) {
                head = temp->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    cout << "Count: " << count << endl;
}

void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    push(head, 1);
    push(head, 3);
    push(head, 1);
    push(head, 2);
    push(head, 1);
    push(head, 2);
    push(head, 1);
    cout << "Original List: ";
    display(head);
    countAndDelete(head, 1);
    cout << "Updated List: ";
    display(head);
}

