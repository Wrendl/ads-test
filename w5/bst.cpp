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

    Node *search(Node *root, int key){
        if(!root || root->data == key) return root;

        else if(key <= root->data) return search(root->left, key);

        return search(root->right, key);
    }

    Node  *delete_node(Node *root, int key){
        if(!root) return root;

        // find node
        if (key <= root->data) {
            root->left = delete_node(root->left, key);
            return root;
        }
        else if (key > root->data) {
            root->right = delete_node(root->right, key);
            return root;
        }

        // 1st case, if children is empty
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 2nd case, if both childrens exists
        else {
            // find successor of the node
            Node* succParent = root;
    
            Node* succ = root->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }

            if (succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            root->data = succ->data;

            delete succ;
            return root;
        }

    }

};

int main() {
    Tree *t = new Tree();
    Node *root = t->insert_node(NULL, 10);

    t->insert_node(root, 7);
    t->insert_node(root, 20);
    t->insert_node(root, 6);

    t->inOrder(root);
    cout<<endl;

    int key = 6;
    Node *node = t->search(root, key);
    cout<<node->data<<endl;

    node = t->delete_node(root, key);
    cout<<node->data<<endl;
    t->inOrder(root);

    return 0;
}