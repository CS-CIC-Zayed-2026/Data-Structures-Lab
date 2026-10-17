//
// Created by a_m_s on 10/17/26.
//

/*
 * Problem: Implement a Dynamic Stack Using an Array
 *
 * Description:
 * Implement a Stack using a dynamically allocated array that automatically
 * increases its capacity when the stack becomes full.
 *
 * Required Operations:
 * - push(value): Add an element to the top of the stack.
 * - pop(): Remove the top element.
 * - peek(): Return the top element without removing it.
 * - isEmpty(): Check whether the stack is empty.
 * - display(): Print all elements from top to bottom.
 * - getSize(): Return the number of elements in the stack.
 *
 * Note: The stack should grow automatically without requiring a fixed size from the user.
 */

#include <cassert>
#include<iostream>
using namespace std;

class Stack {
private:
    int size;
    int top;
    int *arr;

    void resize() {
        cout<<"Stack Resize"<<endl;
        int new_size = size * 2;
        int *newArr = new int[new_size];

        for (int i = 0; i <= top; i++) {
            newArr[i] = arr[i];
        }

        delete [] arr;
        arr = newArr;
        size = new_size;
    }

    bool isFull() {
        return top == size - 1;
    }

public:
    Stack() {
        size = 2;
        top = -1;
        arr = new int[size];
    }

    ~Stack() {
        delete [] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            resize();
        }
        arr[++top] = value;
    }

    void pop() {
        assert(!isEmpty());
        --top;
    }

    int peek() {
        assert(!isEmpty());
        return arr[top];
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getSize() {
        return top + 1;
    }
};

int main() {

    Stack s;
    cout << "size is : " << s.getSize() << endl;
    s.push(1);
    cout << "size is : " << s.getSize() << endl;
    cout << "peek is : " << s.peek() << endl;
    s.push(2);
    s.push(3);
    s.display();
    cout << "size is : " << s.getSize() << endl;

    return 0;
}