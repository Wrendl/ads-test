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

    int height(Node* node) {
        if(!node) return 0;

        else {
            int lHeight = height(node->left);
            int rHeight = height(node->right);

            if (lHeight > rHeight)
                return (lHeight + 1);
            else
                return (rHeight + 1);
        }
    }

    int height2(Node* node) {
        if(!node) return 0;

        else {
            int lHeight = height(node->left);
            int rHeight = height(node->right);

            return max(lHeight, rHeight);
        }
    }
};

int main() {
    Tree *t = new Tree();
    Node *root = t->insert_node(NULL, 8);

    t->insert_node(root, 3);
    t->insert_node(root, 6);
    t->insert_node(root, 1);
    t->insert_node(root, 4);
    t->insert_node(root, 7);
    t->insert_node(root, 10);
    t->insert_node(root, 14);
    t->insert_node(root, 13);

    t->inOrder(root);
    cout<<endl;
    cout<<t->height2(root);

    return 0;
}