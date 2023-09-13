// Node object
// queue [1,2,3,4,5]
// node data->int

// node1 => int data = 1
// node2 => int data = 2
// node1 => next = node2 // prev
//
// node1.next.next = node3


// node1    node2

#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
    Node(){
        next = NULL;
        prev = NULL;
    }
};

int main () {
    Node *node1 = new Node(1);
    Node *node2;
    node2->data = 2;

    node1->next = node2;
    node2->prev = node1;

    cout<<node2->prev->data;
}