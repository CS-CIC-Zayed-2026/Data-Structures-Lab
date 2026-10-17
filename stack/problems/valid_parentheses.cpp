//
// Created by a_m_s on 10/17/26.
//

/*
 * Problem: Valid Parentheses
 * Problem link:  https://leetcode.com/problems/valid-parentheses
 *
 * Description:
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * - Open brackets must be closed by the same type of brackets.
 * - Open brackets must be closed in the correct order.
 * - Every close bracket has a corresponding open bracket of the same type.
 *
 * Input: s = "()"      Output: true
 * Input: s = "()[]{}"  Output: true
 * Input: s = "(]"      Output: false
 * Input: s = "([])"    Output: true
 * Input: s = "([)]"    Output: false
 */

#include <cassert>
#include <iostream>
using namespace std;

class Stack {
private:
    int size;
    int top;
    char *arr;
public:
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new char[size];
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

    void push(char value) {
        assert(!isFull());
        arr[++top] = value;
    }

    void pop() {
        assert(!isEmpty());
        --top;
    }

    char peek() {
        assert(!isEmpty());
        return arr[top];
    }
};

char get_open(char ch) {
    if (ch == ')') return '(';
    if (ch == ']') return '[';
    if (ch == '}') return '{';
}

bool isValid(string in) {
    int size = in.size();
    Stack st(size);
    for (int i = 0; i < size; i++) {
        char ch = in[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }
        else if (!st.isEmpty() && st.peek() == get_open(ch)) {
            st.pop();
        } else return false;
    }

    return st.isEmpty();
}

int main() {
    cout << isValid("]") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("(]") << endl;
    cout << isValid("([])") << endl;
    cout << isValid("(())") << endl;
    cout << isValid("([)]") << endl;
    cout << isValid("(()[()])") << endl;
    cout << isValid("(][)") << endl;
    cout << isValid("(()") << endl;
    cout << isValid("()(") << endl;
    return 0;
}