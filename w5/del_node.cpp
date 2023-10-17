#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        // next = NULL;
        // prev = NULL;
    }
};

int main () {
    Node *node = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);

    node->next = node2;
    node2->next = node3;
    delete node2;

    cout<<node->data<<endl;
    cout<<node2->data<<endl;
    cout<<node3->data<<endl;
    cout<<node2->next->data<<endl;
    // cout<<node->next->data<<endl;
    // cout<<node2->next->data<<endl;
    // cout<<node3->data<<endl;

    // cout<<node->prev;
}