// queue deque stack
// struck function class

#include <iostream>

using namespace std;

const int MAX_INT = 1000;

struct queue {
    int first;
    int sz;
    int a[MAX_INT];

    queue(){
        first = 0;
        sz = 0;
    }

    void push_back(int x){
        a[sz] = x;
        sz++;
    }

    void print(){
        for (int i=first; i<sz; i++){
            cout<<a[i]<<" ";
        }
    }

    void pop_front(){
        first++;
    }
};

int main() {
    queue q;

    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.pop_front();

    q.print();
}