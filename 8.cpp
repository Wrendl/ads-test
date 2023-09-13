// include algorithm, queue deque stack
// struct class 
#include <iostream>

using namespace std;

const int MAX_INT = 1000;

struct queue {
    int sz;
    int first;
    int a[MAX_INT];

    queue(){
        sz = 0;
        first = 0;
    }
    void push_back(int x){
        a[sz] = x;
        sz++;
    }
    void pop_front(){
        first++;
    }
    void print(){
        for(int i=first; i<sz; i++){
            cout<<a[i]<<" ";
        }
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