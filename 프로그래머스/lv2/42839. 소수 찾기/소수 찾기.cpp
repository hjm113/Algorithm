#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int prime[10000000];
int chk[10000000];
vector<char> c;
int n = 0;
set<int> s;
int cnt = 0;
int solution(string numbers) {
    n = numbers.length();
    int answer = 0;
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i*i <= 10000000; i++) {
        if(prime[i] == 1) {
            continue;
        }
        for(int j = i*i; j <= 10000000; j+= i) {
            prime[j] = 1;
        }
    }
    // 저 아이디어는 진짜 천재다
    for(int i = 0; i < n; i++) {
        c.push_back(numbers[i]);
    }
    sort(c.begin(),c.end());
    do {
        string tmp = "";
        for(int i = 0; i < n; i++) {
            tmp += c[i];
            s.insert(stoi(tmp));
        }
    }while(next_permutation(c.begin(),c.end()));
    for(auto ele : s) {
        if(prime[ele] == 0) {
            cnt++;
        }
    }
    answer = cnt;
    return answer;
}