//
// Created by a_m_s on 10/17/26.
//

/*
 * Problem : Min Stack
 * Problem link: https://leetcode.com/problems/min-stack/
 *
 * Description:
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * Implement the MinStack class:
 * - MinStack() initializes the stack object.
 * - void push(int value) pushes the element value onto the stack.
 * - void pop() removes the element on the top of the stack.
 * - int top() gets the top element of the stack.
 * - int getMin() retrieves the minimum element in the stack.
 * You must implement a solution with O(1) time complexity for each function.
 */


#include <cassert>
#include <climits>
#include <iostream>
using namespace std;

struct StackVal {
    int value;
    int mn;
};

class MinStack {
private:
    int size;
    int top;
    StackVal *arr;
    int mn;

    void resize() {
        int new_size = size * 2;
        StackVal *newArr = new StackVal[new_size];

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
    MinStack() {
        size = 10;
        top = -1;
        arr = new StackVal[size];
        mn = INT_MAX;
    }

    ~MinStack() {
        delete [] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            resize();
        }
        if (isEmpty()) mn = value;
        mn = min(mn, value);
        arr[++top] = {value, mn};
    }

    void pop() {
        assert(!isEmpty());
        --top;
        if (!isEmpty())
            mn = arr[top].mn;
    }

    int peek() {
        assert(!isEmpty());
        return arr[top].value;
    }

    int getMin() {
        assert(!isEmpty());
        return arr[top].mn;
    }

    int getSize() {
        return top + 1;
    }
};


int main() {

    MinStack s;
    s.push(1);
    s.push(2);
    cout << s.peek() << endl;
    cout << s.getMin() << endl;
    s.push(-3);
    cout << s.peek() << endl;
    cout << s.getMin() << endl;
    s.pop();
    cout << s.peek() << endl;
    cout << s.getMin() << endl;
    return 0;
}