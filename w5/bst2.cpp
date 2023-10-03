#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree {
    public:
    Node *root;
    Tree(int root) {
        this->root = new Node(root);
    }

    Node *insert_node(Node *node, int data) {
        if (!node) return new Node(data);

        if (data <= node->data) {
            node->left = insert_node(node->left, data);
        } else if (data > node->data){
            node->right = insert_node(node->right, data);
        }
        return node;
    }

    void inOrder(Node *node){
        if(!node) return;

        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }

    Node *search(Node *node, int key){
        if(!node || node->data == key) return node;

        else if(key <= node->data) return search(node->left, key);

        return search(node->right, key);
    }

    Node *delete_node(Node *node, int key) {
        if(!node) return node;

        // find node
        if (key <= node->data) {
            node->left = delete_node(node->left, key);
            return node;
        }
        else if (key > node->data) {
            node->right = delete_node(node->right, key);
            return node;
        }

        // 1st case, if children is empty
        if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // 2nd case, if both childrens exists
        else {
            // find successor of the node
            Node* succParent = node;
    
            Node* succ = node->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }

            if (succParent != node)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            node->data = succ->data;

            delete succ;
            return node;
        }

    }

};

int main() {
    Tree *t = new Tree(10);

    t->insert_node(t->root, 7);
    t->insert_node(t->root, 20);
    t->insert_node(t->root, 6);

    t->inOrder(t->root);
    cout<<endl;

    int key = 20;
    Node *node = t->search(t->root, key);
    cout<<node->data;

    return 0;
}