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

struct queue {
    int sz;
    Node* first;
    Node* last;

    queue(){
        sz = 0;
        first = NULL;
        last = NULL;
    }

    void push_back(int x){
        Node* node = new Node(x); // 1      2   3 4 5
        if (sz == 0){             // first last~last 
            first = node;
            first->next = last;
        }
        last->next = node;
        last = node;
        sz++;
    }
    void pop_front();
    void print();
};


int main() {
    queue q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    // q.pop_front();
    // q.print();
    // Node* node1 = new Node(1);
    // Node* node2 = new Node(2);
    // node1->next = node2;

    // cout<<node1->next->data;
}