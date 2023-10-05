#include <string>
#include <map>
#include <iostream>
using namespace std;
map<string, int> mp1;
map<string, int> mp2;
int solution(string str1, string str2) {
    int answer = 0;
    for(int i = 0; i < str1.length(); i++) {
        if(str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] = tolower(str1[i]);
        }
    }
    for(int i = 0; i < str2.length(); i++) {
        if(str2[i] >= 'A' && str2[i] <= 'Z') {
            str2[i] = tolower(str2[i]);
        }
    }
    for(int i = 0; i < str1.length()-1; i++) {
        mp1[str1.substr(i,2)]++;
    }
    for(int i = 0; i < str2.length()-1; i++) {
        mp2[str2.substr(i,2)]++;
    }
    double sum1 = 0;
    double sum2 = 0;
    for(char i = 'a'; i <= 'z'; i++) {
        for(char j = 'a'; j <= 'z'; j++) {
            string tmp = "";
            tmp += i;
            tmp += j;
            sum1 += min(mp1[tmp],mp2[tmp]);
            sum2 += max(mp1[tmp],mp2[tmp]);
        }
    }
    if(sum2 == 0) {
        answer = 1*65536;
        return answer;
    }
    /*
    cout << mp1["aa"] << "\n";
    cout << mp2["aa"] << "\n";
    cout << sum1 << " " << sum2 << "\n";
    */
    answer = sum1/sum2*65536;
    return answer;
}