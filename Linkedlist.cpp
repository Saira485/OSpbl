#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();

    return 0;
}
