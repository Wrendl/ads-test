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
};

class LinkedList {
    public:
    Node *head, *tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            tail->next = NULL;
        }
    }

    void pop_front() {
        if (head != NULL) {
            head = head->next;
            head->prev = NULL;
        }
    }

    void push_back(int data) {
        Node *node = new Node(data);

        if (tail == NULL) {
            tail = node;
            head = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    } 

    void push_front(int data) {
        Node *node = new Node(data);
        if (head == NULL) {
            tail = node;
            head = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
    }

    void delete_element(Node *node) {
        if (node == head)
            pop_front();
        else if(node == tail)
            pop_back();
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }

    void insert(Node *node1, Node *node2) {
        if (node1 == tail)
            push_back(node2->data);
        else {    
            node1->next->prev = node2;
            node2->next = node1->next;
            node1->next = node2;
            node2->prev = node1;
        }
    }
    
    void insert_by_ind(Node *node, int ind) {
        if (ind == 0){
            push_front(node->data);
        }
        else {
            Node *top = head;
            int cnt = 0;
            while (ind!=cnt && top->next!=NULL){
                top = top->next;
                cnt++;
            }
            if (top->next==NULL) {
                push_back(node->data);
            }
            else{
                top->next->prev = node;
                node->next = top->next;
                top->next = node;
                top->prev = top;
            }
        }
    }

    Node* search(int data) {
        Node *node = head;
        while (node != NULL && node->data != data)
            node = node->next;
        return node;
    }

    void print() {
        Node *node = head;
        while (node != NULL) {
            cout << node->data << "-->";
            node = node->next;
        }   
        cout << endl;
    }
};

int main() {
    LinkedList *ll = new LinkedList();
    ll->push_back(1);
    ll->push_back(2);
    ll->push_back(3);
    ll->push_back(4);
    ll->push_back(5);
    ll->print();

    Node *node = new Node(6);
    ll->insert_by_ind(node, 5);
    ll->print();

    // ll->pop_front();
    // ll->pop_back();
    // ll->print();

    // Node *node = ll->search(5);
    // cout<<node->data<<endl;

    // ll->delete_element(node);
    // ll->print();

    // Node *node1 = new Node(4);

    // ll->insert(node, node1);
    // ll->print();

    return 0;
}
