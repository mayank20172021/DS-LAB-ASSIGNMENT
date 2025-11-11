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

void findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle Element: " << slow->data << endl;
}

int main() {
    Node* head = NULL;
    for (int i = 5; i >= 1; i--)
        push(head, i);
    cout << "List: 1->2->3->4->5\n";
    findMiddle(head);
}

