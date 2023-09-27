#include <iostream>

using namespace std;
// 8 12 = 4
// 8 0 = 8
int gcd(int a, int b) {
    if (a == 0 || b == 0)
        return a + b;
    return gcd(b, a % b);
    // 8 12
    // 12 8
    // 8 4
    // 4 0
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}