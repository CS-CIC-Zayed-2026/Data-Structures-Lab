#include <iostream>
using namespace std;

const int SIZE = 10;
int arr[SIZE];
int top = -1;

bool isFull() {
    return top == SIZE - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int val) {
    if (isFull()) {
        cout << "Stack is full" << endl;
        return;
    }

    ++top;
    arr[top] = val;
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return arr[top];
}

void pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    --top;
}

int main() {

    push(5);
    cout << peek() << endl;
    push(10);
    cout << peek() << endl;
    pop();
    cout << peek() << endl;
    pop();
    cout << peek() << endl;
    pop();
    return 0;
}