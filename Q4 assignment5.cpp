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

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void display(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    for (int i = 4; i >= 1; i--)
        push(head, i);
    cout << "Original List: ";
    display(head);
    head = reverse(head);
    cout << "Reversed List: ";
    display(head);
}

