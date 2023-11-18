#include <iostream>
#include <vector>

using namespace std;

// s[0] * 31^0
// s[1] * 31^1

// s[] = s[0] + s[1]*31 + s[2]*31^2 + s[3]*32^3
// a[] = s[1] + s[2]*31

// v[4] = vector
// v[0] = s[0]
// v[1] = s[0] + s[1]*31
// v[2] = s[0] + s[1]*31 + s[2]*31^2
// v[3] = s[0] + s[1]*31 + s[2]*31^2 + s[3]*32^3

// abacababa
// aba
// aba # abacababa
// 001 0 123012323

// aab # aabaaaab
// 010 0 12312223

// a[] = s[1] + s[2]*31
// v[3] - v[3-2] = 


// ab
// ababa

// s[0] + s[1]*31

// v[5]
// v[0] = S[0]
// v[1] = S[0] + S[1]*31
// v[2] = v[1] + s[2]*31*2
// v[3] = S[0] + S[1]*31 + s[2]*31*2+ S[3]*31^3


// s[2]*31*2+ S[3]*31^3
// (s[0] + s[1]*31)* 31^2






int calc_hash(string s) {
    int h = 0;
    int p = 31;
    int p_pow = 1;

    for (int i = 0; i < s.size(); i++) {
        h += (s[i] - 'a' + 1) * p_pow;
        p_pow *= 31;
    }
    // bc
    // 2 + 3 * 31^1 = 95
    return h;
}

vector<int> find_hash(string s) {
    int n = s.size();
    vector<int> h(n);
    int p = 31;
    int p_pow = 1;
    h[0] = s[0] - 'a' + 1;

    for (int i = 1; i < n; i++) {
        p_pow *= 31;
        h[i] = h[i - 1] + (s[i] - 'a' + 1) * p_pow;
    }

    return h;
}  

int main() {
    string s, t;
    cin >> s >> t;

    // abca
    // bc = 

    int hash_t = calc_hash(t);
    vector<int> hash = find_hash(s);
    int n = s.size();
    int m = t.size();
    int p[n];
    p[0] = 1;

    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] * 31;

    for (int i = 0; i < n - m + 1; i++) {
        int j = i + m - 1;
        int hashij = hash[j];
        if (i > 0)
            hashij -= hash[i - 1];
        if (hashij == hash_t * p[i]) {
            cout << i << " ";
        }
    }

    return 0;
}