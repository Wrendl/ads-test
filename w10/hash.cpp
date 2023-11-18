#include <iostream>
#include <vector>

using namespace std;

int calc_hash(string s) {
    int h = 0;
    int p = 31;
    int p_pow = 1;

    for (int i = 0; i < s.size(); i++) {
        h += (s[i] - 'a') * p_pow;
        p_pow *= 31;
    }
    return h;
}

int main() {
    // string s;
    // cin >> s;

    // int hash_s = calc_hash(s);
    // cout<<hash_s;

    char a = 'a';
    cout<<int(a); 

    return 0;
}


// fdhsjkgfhdjklg = 9999
// 