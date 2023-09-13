#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    // Node *prev;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

struct queue{
    int sz;
    Node* top;

    queue(){
        sz = 0;
    }

    void push_back(int x){
        Node* node = new Node(x);
        top->next = node;
        top = node;
    }
    void pop_front(){
        if(top->next!=NULL){
            top = top->next;
        }
    }
    void print();
};

int main() {
    Node* node = new Node(1);
    Node* node2 = new Node(2);
    // node->next = node2;

    queue q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);

    // cout<<node->next->data;
}