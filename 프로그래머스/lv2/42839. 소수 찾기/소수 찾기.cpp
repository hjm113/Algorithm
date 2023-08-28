#include <string>
#include <vector>
#include <iostream>
using namespace std;
int prime[10000000];
int n = 0;
char ary[10];
int used[10];
int chk[10000000];
string a;
int cnt = 0;
void dfs(int k) {
    int num = 0;
    int d = 1;
    for(int i = 0; i < k; i++) {
        cout << ary[i];
        num += (ary[i]-'0')*d;
        d *= 10;
    }
    cout << "\n";
    if(chk[num] == 0) {
        if(prime[num] == 0) {
            cnt++;
        }
        chk[num] = 1;
    }
    if(k == n) {
        return;
    }
    for(int i = 0; i < n; i++) {
        if(used[i] == 1) {
            continue;
        }
        used[i] = 1;
        ary[k] = a[i];
        dfs(k+1);
        used[i] = 0;
    }
}

int solution(string numbers) {
    a = numbers;
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
    n = numbers.length();
    dfs(0);
    answer = cnt;
    return answer;
}