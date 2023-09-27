#include <iostream>
using namespace std;
// 2*10 = x
int m_pow(int a, int b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int res = m_pow(a, b / 2);
    if (b % 2 == 0)
        return res * res;
    return res * res * a;
    // 2*5 = 32
    // 1st state -> res=?, a=2, b=5
    // 2nd state -> res=8, a=2, b=2,  
    // 3rd state -> res=2, a=2, b=1
    // 4th state -> res=2, a=2, b=1
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << m_pow(a, b);
    return 0;
}