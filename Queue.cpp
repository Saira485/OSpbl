#include <iostream>
using namespace std;

#define MAX 5
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX - 1) {
        cout << "Queue Full\n";
    } else {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = x;
        cout << x << " inserted\n";
    }
}

void dequeue() {
    if(front == -1 || front > rear) {
        cout << "Queue Empty\n";
    } else {
        cout << queue[front] << " removed\n";
        front++;
    }
}

void display() {
    for(int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();

    return 0;
}
