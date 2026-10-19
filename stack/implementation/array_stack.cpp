//
// Created by a_m_s on 10/17/26.
//

/*
 * Data Structure: Stack
 * Implementation: Array
 *
 * Operations:
 * - push
 * - pop
 * - peek
 * - isEmpty
 * - isFull
*/

// Headers
#include <iostream>
using namespace std;

// Stack implementation
class Stack {
private:
    int size;
    int top;
    int *arr;   // Dynamic
    // int arr[SIZE] // fixed
public:
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout<<"Stack is full"<<endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout<<"Stack is empty"<<endl;
            return;
        }
        --top;
    }

    int peek() {

        if (isEmpty()) {
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        return arr[top];
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(10);
    cout << "Stack is empty: " << s.isEmpty() << endl;
    cout << "Stack is full: " << s.isFull() << endl;
    cout << s.peek() << endl;
    s.push(10);
    cout << s.peek() << endl;
    s.push(20);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    return 0;
}