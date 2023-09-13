// 1,2,3,4,5

// node -> data

// (node1) -> 1
// (node2) -> 2
// (node3) -> 3

// queue = node1, node2, node3;
// node1.next => node2;
// node1.next.next => node3.data;

#include <iostream>
#include <algorithm>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
    }
    Node();
};

int main () {
    Node *node1 = new Node(5);
    node1->data = 6;

    Node *node2;
    node2->data = 7;

    node1->next = node2;
    node2->prev = node1;
    cout<<node1->next->data<<" "<<node2->prev->data;

}
