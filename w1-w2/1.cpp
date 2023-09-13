#include <iostream>

using namespace std;

struct node{
    int val;
    node * next;
};

struct node1{
    int val;
    node * next;
    node * prev;
    node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class myqueue {
    public:
        int a[10];
        int last;
        int first;

        myqueue() {
            first = 0;
            last = 0;
        }

        int val() {
            return a[first];
        }

        void add(int x) {
            a[last] = x;
            last++;
        }

        void del() {
            first++;
        }

};

int main() {
    myqueue q;

    q.add(1);
    q.add(2);

    cout<<q.val()<<endl;

    q.del();

    cout<<q.val()<<endl;
}