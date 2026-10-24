//
// Created by a_m_s on 10/24/26.
//

#include <iostream>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    int size;
    int current_element;
    int *arr;

public:
    Queue(int size) {
        front = 0;
        rear = 0;
        current_element = 0;
        this->size = size;
        arr = new int[size];
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return current_element == 0;
    }

    bool isFull() {
        return current_element == size;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout<<"Queue is full"<<endl;
            return;
        }

        arr[rear] = element;
        rear = (rear + 1) % size;

        /*
        ++rear;
        if (rear == size) {
            rear = 0;
        }
        */

        current_element++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        front = (front + 1) % size;

        /*
        ++front;
        if (front == size) {
            front = 0;
        }
        */
        current_element--;
    }

    int peek() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }


        int cur = front;
        for (int i = 0 ; i < current_element; i++) {
            cout<<arr[cur]<<" ";
            cur = (cur + 1) % size;
        }



        // for (int i = 0 ; i < current_element; i++) {
        //     cout << arr[(front + i) % size] << " ";
        // }


        cout<<endl;

    }
};

int main() {
    Queue q(5);
    cout << q.peek() << endl;
    q.display();
    cout << "Insert " << endl;
    q.enqueue(1);
    cout << q.peek() << endl;
    q.enqueue(2);
    cout << q.peek() << endl;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    q.dequeue();
    cout << q.peek() << endl;
    q.display();
    q.enqueue(7);
    cout << q.peek() << endl;
    q.display();
    q.dequeue();
    cout << q.peek() << endl;
    q.display();
    q.dequeue();
    cout << q.peek() << endl;
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    q.dequeue();
    q.enqueue(8);
    cout << q.peek() << endl;
}