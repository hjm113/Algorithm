#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
void hanoi(int a, int b, int n) {
    if(n == 1) {
        answer.push_back({a,b});
        return;
    }
    hanoi(a,6-a-b,n-1);
    answer.push_back({a,b});
    hanoi(6-a-b,b,n-1);
}
vector<vector<int>> solution(int n) {
    hanoi(1,3,n);
    return answer;
}