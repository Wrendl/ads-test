// Node object
// queue [1,2,3,4,5]
// node1 -> data
// node1 => data->1
// node2 => data->2

// node1->next = node2->data
// node1->next->next = node3

#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
    Node();
};

int main () {
    Node *node1 = new Node(6);
    Node *node2;
    node2->data = 5;

    node1->next = node2;
    
    cout<<node1->next->data;
}