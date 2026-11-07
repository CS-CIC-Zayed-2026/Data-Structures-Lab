#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~LinkedList() {
        while (head != NULL) {
            Node* temp = head->next;
            delete head;
            head = temp;
        }
    }

    void print() {
        // Node* temp = head;
        // while (temp != NULL) {
        //     cout << temp->data << " ";
        //     temp = temp->next;
        // }
        // cout << endl;

        for (Node *p = head; p != NULL; p = p->next) {
            cout << p->data << " ";
        }
        cout << endl;
    }

    void insert_end(int value) {
        Node* new_node = new Node(value);

        // Case one : List empty (head and tail = null)
        if (head == NULL) { // if (!head)
            head = new_node;
            tail = new_node;
            // head = tail = new_node;
        } // Case 2 : List contain one or more items
        else {
            tail->next = new_node;
            tail = new_node;
        }

        ++size;
    }

    void insert_front(int value) {
        Node* new_node = new Node(value);

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }

        ++size;
    }

    void insert_nth(int idx, int value) {
        if (idx < 1 || idx > size) {
            cout << "Index out of range" << endl;
            return;
        }

        if (idx == 1) {
            insert_front(value);
            return;
        }

        // if (idx == size) {
        //     insert_end(value);
        //     return;
        // }

        Node* new_node = new Node(value);
        Node* prv = get_nth(idx - 1);
        Node* nxt = prv->next;

        new_node->next = nxt;
        prv->next = new_node;
        ++size;
    }

    void delete_front() {
        if (head == NULL) // if (size == 0)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* p = head;
        head = head->next;
        delete p;

        if (size <= 1) {
            tail = head;
        }

        --size;
    }

    Node* get_nth(int n) {
        int cnt = 1;
        for (Node *p = head; p != NULL; p = p->next) {
            if (cnt == n) {
                return p;
            }
            ++cnt;
        }

        return NULL;
    }

    void delete_end() {
        if (size <= 1) {
            delete_front();
            return;
        }

        Node* p = head;
        while (p->next != tail) {
            p = p->next;
        }
        /*
        Node * prv = get_nth(size - 1);
        delete tail;
        tail = prv;
        tail->next = NULL;
        */

        delete tail;
        tail = p;
        tail->next = NULL;
        --size;

    }

    void delete_nth_node(int idx) {
        if (idx < 1 || idx > size) {
            cout << "Index out of range" << endl;
            return;
        }

        if (idx == 1) {
            delete_front();
            return;
        }

        Node *prv = get_nth(idx - 1);
        Node *cur = prv->next;

        prv->next = cur->next;
        if (cur == tail) {
            tail = prv;
        }
        --size;
    }

    int get_size() {
        return size;
    }
};

int main() {

    LinkedList ll;
    ll.insert_end(1);
    ll.insert_end(2);
    ll.insert_end(3);
    ll.print();
    ll.insert_front(4);
    ll.insert_front(5);
    ll.print();
    ll.delete_front();
    ll.print();
    ll.delete_end();
    ll.print();
    ll.delete_nth_node(1);
    ll.print();
    ll.delete_end();
    ll.print();
    ll.delete_front();
    ll.print();
    ll.insert_front(6);
    ll.print();
    ll.insert_end(7);
    ll.print();
    ll.insert_nth(1,-10);
    ll.print();
    ll.insert_nth(3,-10);
    ll.print();
    ll.delete_nth_node(3);
    ll.print();
    ll.delete_nth_node(3);
    ll.print();

    return 0;
}