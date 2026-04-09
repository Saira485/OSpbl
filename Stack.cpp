#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX], top = -1;

void push(int x) {
    if(top == MAX - 1) {
        cout << "Stack Overflow\n";
    } else {
        top++;
        stack[top] = x;
        cout << x << " pushed\n";
    }
}

void pop() {
    if(top == -1) {
        cout << "Stack Underflow\n";
    } else {
        cout << stack[top] << " popped\n";
        top--;
    }
}

void display() {
    for(int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();

    return 0;
}
