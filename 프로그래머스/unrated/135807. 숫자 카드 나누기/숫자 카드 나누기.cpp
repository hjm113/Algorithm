#include <string>
#include <vector>

using namespace std;
int gcd(int x, int y) {
    if(x == 0) {
        return y;
    }
    return gcd(y%x,x);
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int n = arrayA.size();
    int a = arrayA[0];
    for(int i = 1; i < n; i++) {
        a = gcd(a,arrayA[i]);
    }
    int chk = 0;
    for(int i = 0; i < n; i++) {
        if(arrayB[i] % a == 0) {
            chk = 1;
        }
    }
    if(chk == 0) {
        answer = a;
    }
    int b = arrayB[0];
    for(int i = 1; i < n; i++) {
        b = gcd(b,arrayB[i]);
    }
    chk = 0;
    for(int i = 0; i < n; i++) {
        if(arrayA[i] % b == 0) {
            chk = 1;
        }
    }
    if(chk == 0) {
        answer = max(answer,b);
    }
    return answer;
}