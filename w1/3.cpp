#include <iostream>

using namespace std;

const int MAX_SIZE=1000;

struct queue {
    int m_name;
    int m_size;
    int m_start;
    string m_elems[MAX_SIZE];

    queue(int name){
        m_name = name;
        m_size = 0;
        m_start = 0;
    }
    void push(string d) {
        m_elems[m_size] = d;
        m_size++;
    }
    void print(){
        for (int i=0; i<m_size; i++) {
            cout<<m_name<<" "<<m_elems[i]<<endl;
        }
    }
};

int main() {
    // int cnt = 0;
    queue nine(9);
    queue ten(10);
    queue eleven(11);

    int n;
    string s;

    while(cin>>n>>s){
        // cin>>n>>s;
        
        if(n==9){
            nine.push(s);
        }
        if(n==10){
            ten.push(s);
        }
        if(n==11){
            eleven.push(s);
        }
    }

    nine.print();
    ten.print();
    eleven.print();
}