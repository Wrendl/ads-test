#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_func(string s) {
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i]) 
            j = p[j - 1];
        if (s[j] == s[i]) j++;
        p[i] = j;
    }

    return p;
}

int main() {
    string a, b, s;
    cin >> a >> b;
    int b_sz = b.size();
    s = b + '#' + a;
    cout << s << endl;

    vector<int> p = prefix_func(s);

    for (int i = 0; i < s.size(); i++) {
        if (p[i] == b_sz) {
            cout << "substr is found at index " << i - 2*b_sz;
        }
    }
    
    return 0;
}