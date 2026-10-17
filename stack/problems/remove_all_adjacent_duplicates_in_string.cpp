//
// Created by a_m_s on 10/17/26.
//

/*
 * Problem: Remove All Adjacent Duplicates In String
 * Problem link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string
 *
 * Description:
 * You are given a string s consisting of lowercase English letters.
 * A duplicate removal consists of choosing two adjacent and equal letters and removing them.
 * We repeatedly make duplicate removals on s until we no longer can.
 * Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
 *
 * Input: s = "abbaca"      Output: "ca"
 * Input: s = "azxxzy"      Output: "ay"
 */

#include <algorithm>
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

string solve(string in) {
    int size = in.size();
    Stack st(size);
    for (int i = 0; i < size; i++) {
        char c = in[i];
        if (!st.isEmpty() && st.peek() == c) {
            st.pop();
        }
        else st.push(c);
    }

    string result = "";
    while (!st.isEmpty()) {
        result += st.peek();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    cout << solve("azxxzy") << endl;
    return 0;
}