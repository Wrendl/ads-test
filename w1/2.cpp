#include <iostream>

using namespace std;

const int MAX_SIZE=1000;
     
struct stack {
    int sz;
    int m_elems[MAX_SIZE];

    stack(){
        sz = 0;
    }
    void push(int d){
        m_elems[sz] = d;
        sz++;
        cout<<"ok"<<endl;
    }
    int pop(){
        sz--;
        return m_elems[sz];
    }
    int back(){
        return m_elems[sz-1];
    }
    int size(){
        return sz;
    }
    void clear(){
        sz = 0;
        cout<<"ok"<<endl;
    }
};

struct queue {
    int m_size;
    int m_start;
    int m_elems[MAX_SIZE];

    queue();
    ~queue();
    void push(int d);
    int pop();
    int front();
    int size();
    void clear();
};

int main () {
    stack s;

    while(1) {
        string x;
        cin>>x;

        if (x=="exit") {
            cout<<"bye"<<endl;
            return false;
        }

        else if (x=="push") {
            int n;
            cin>>n;
            s.push(n);
        }

        else if (x=="pop") {
            cout<<s.pop()<<endl;
        }

        else if (x=="back") {
            cout<<s.back()<<endl;
        }

        else if (x=="size") {
            cout<<s.size()<<endl;
        }

        else if (x=="clear") {
            s.clear();
        }
    }
}