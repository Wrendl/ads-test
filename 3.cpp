#include <iostream>

using namespace std;

const int MAX_INT = 1000;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};


int main() {
    Node* top;
    Node *node = new Node(5);
    top->next = node;
    cout<<top->next->data;
    // queue q;

    // q.push_back(1);
    // q.push_back(2);
    // q.push_back(3);
    // q.pop_front();

    // q.print();
}