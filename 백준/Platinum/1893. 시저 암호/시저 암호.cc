#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int t;
string a, w, s;
vector<int> pi;
vector<int> r;
void getpi(string b) {
    pi.clear();
    pi.resize(b.length());
    int j = 0;
    for (int i = 1; i < b.length(); i++) {
        while (j > 0 && b[i] != b[j])
            j = pi[j - 1];       
        if (b[i] == b[j])
            pi[i] = ++j;     
    }
}
int kmp(string a, string b) {
    int j = 0;
    int ret = 0;
    for (int i = 0; i < a.length(); i++) {
        while (j > 0 && a[i] != b[j])
            j = pi[j - 1];
        if (a[i] == b[j]) {
            if (j == b.length() - 1) {
                ret++;
                j = pi[j];
            }
            else
                j++;
        }
    }
    return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
    while (t--) {
        cin >> a >> w >> s;
        int n = a.length();
        r.clear();
        map<char, int> mp;
        map<int, char> rmp;
        for (int i = 0; i < n; i++) {
            mp[a[i]] = i;
            rmp[i] = a[i];
        }
        for (int i = 0; i < n; i++) {
            if (i) {
                for (int j = 0; j < w.length(); j++) {
                    w[j] = rmp[(mp[w[j]] + 1) % n];
                }
            }
            getpi(w);
            if (kmp(s, w) == 1)
                r.push_back(i);
        }
        if (!r.size())
            cout << "no solution\n";
        else if (r.size() == 1)
          cout << "unique: " << r[0] << "\n";
        else {
            cout << "ambiguous: ";
            for (int x : r)
                cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
