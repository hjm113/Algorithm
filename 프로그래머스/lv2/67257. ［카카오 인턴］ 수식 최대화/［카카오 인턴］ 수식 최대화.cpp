#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> num;
vector<char> sign;
vector<ll> tmpn;
vector<char> tmps;
vector<char> order;
map<char,int> mp;
long long solution(string expression) {
    long long answer = 0;
    string s1 = "";
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == '*' || expression[i] == '-' || expression[i] == '+' ) {
            if(mp[expression[i]] == 0) {
                order.push_back(expression[i]);
                mp[expression[i]] = 1;
            }
            tmpn.push_back(stol(s1));
            s1 = "";
            tmps.push_back(expression[i]);
            continue;
        }
        s1 += expression[i];
        if(i == expression.length()-1) {
            tmpn.push_back(stol(s1));
        }
    }
    sort(order.begin(),order.end());
    /*
    for(int i = 0; i < tmpn.size(); i++) {
        cout << tmpn[i] << " ";
    }
    cout <<"\n";
    for(int i = 0; i < tmps.size(); i++) {
        cout << tmps[i] << " ";
    }
    */
    do {
        for(int i = 0; i < tmpn.size(); i++) {
            num.push_back(tmpn[i]);
        }
        for(int i = 0; i < tmps.size(); i++) {
            sign.push_back(tmps[i]);
        }
        for(int i = 0; i < order.size(); i++) {
            for(int j = 0; j < sign.size(); j++) {
                if(sign[j] == order[i]) {
                    ll sum = 0;
                    if(sign[j] == '*') {
                        sum = num[j]*num[j+1];
                    }
                    if(sign[j] == '+') {
                        sum = num[j]+num[j+1];
                    }
                    if(sign[j] == '-') {
                        sum = num[j]-num[j+1];
                    }
                    sign.erase(sign.begin()+j);
                    num[j] = sum;
                    num.erase(num.begin()+j+1);
                    j--;
                }
            }
        }
        /*
        for(int i = 0; i < num.size(); i++) {
            cout << num[i] << " ";
        }
        cout <<"\n";
        for(int i = 0; i < sign.size(); i++) {
            cout << sign[i] << " ";
        }
        */
        if(answer < abs(num[0])) {
            answer = abs(num[0]);
        }
        num.clear();
        sign.clear();
    }while(next_permutation(order.begin(),order.end()));
    
    return answer;
}