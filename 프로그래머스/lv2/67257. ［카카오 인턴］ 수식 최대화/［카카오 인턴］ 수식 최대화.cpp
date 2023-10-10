#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> num;
vector<char> sign;
vector<char> order;
map<char,int> mp;
long long solution(string expression) {
    long long answer = 0;
    string tmp = "";
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == '*' || expression[i] == '-' || expression[i] == '+' ) {
            if(mp[expression[i]] == 0) {
                order.push_back(expression[i]);
                mp[expression[i]] = 1;
            }
            num.push_back(stol(tmp));
            tmp = "";
            sign.push_back(expression[i]);
            continue;
        }
        tmp += expression[i];
    }
    sort(order.begin(),order.end());
    do {
        string tmp = expression;
        for(int i = 0; i < order.size(); i++) {
            string s = "";
            string chk = "";
            //cout << order[i] << "\n";
            for(int j = 0; j < tmp.length(); j++) {
                if(tmp[j] == order[i]) {
                    ll a = stol(chk);
                    chk = "";
                    int idx = j+1;
                    chk += tmp[idx];
                    idx++;
                    while(idx < tmp.length() && tmp[idx] >= '0' && tmp[idx] <= '9') {
                        chk += tmp[idx];
                        idx++;
                    }
                    ll b = stol(chk);
                    //cout << a << " " << b <<"\n";
                    ll sum = 0;
                    if(order[i] == '*') {
                        sum = a*b;
                    }
                    if(order[i] == '+') {
                        sum = a+b;
                    }
                    if(order[i] == '-') {
                        sum = a-b;
                    }
                    j = idx-1;
                    //cout << sum << "\n";
                    if(tmp[idx] == order[i]) {
                        chk = to_string(sum);
                    }
                    else {
                        chk = to_string(sum);
                        if(s[s.length()-1] == '-') {
                            if(chk[0] == '-') {
                                s = s.substr(0,s.length()-1);
                                s += chk.substr(1);
                                chk = "";
                                continue;
                            }
                        }
                        s += chk;
                        chk = "";
                    }
                    continue;
                }
                if(tmp[j] == '*' || tmp[j] == '-' || tmp[j] == '+' ) {
                    //cout << chk << "\n";
                    s += chk;
                    s += tmp[j];
                    chk = "";
                    continue;
                }
                chk += tmp[j];
                if(j == tmp.length()-1) {
                    s += chk;
                }
            }
            tmp = s;
            cout << tmp << "\n";
        }
        cout << tmp << "\n";
        if(answer < abs(stol(tmp))) {
            answer = abs(stol(tmp));
        }
        //cout << "\n";
    }while(next_permutation(order.begin(),order.end()));
    return answer;
}