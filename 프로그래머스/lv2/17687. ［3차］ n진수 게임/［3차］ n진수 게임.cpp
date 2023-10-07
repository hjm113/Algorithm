#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string order = "";
char ch[20];
string solution(int n, int t, int m, int p) {
    string answer = "";
    order += '0';
    ch[10] = 'A';
    ch[11] = 'B';
    ch[12] = 'C';
    ch[13] = 'D';
    ch[14] = 'E';
    ch[15] = 'F';
    int cnt = 0;
    for(char c = '0'; c <= '9'; c++) {
        ch[cnt] = c;
        cnt++;
    }
    cnt = 1;
    while(1) {
        int st = cnt;
        string tmp = "";
        while(st > 0) {
            tmp += ch[st%n];
            st /= n;
        }
        cnt++;
        reverse(tmp.begin(),tmp.end());
        order += tmp;
        if(order.length() > 120000) {
            break;
        }
    }
    /*
    for(int i = 0; i < 10; i++) {
        cout << order[i];
    }
    */
    int fst = p-1;
    cnt = 0;
    while(cnt < t) {
        answer += order[fst];
        fst += m;
        cnt++;
    }
    return answer;
}