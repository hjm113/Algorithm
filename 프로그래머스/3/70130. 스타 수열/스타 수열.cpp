#include <string>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int chk[500005];
vector<pair<int,int>> ans;
int solution(vector<int> a) {
    int answer = -1;
    for(int i = 0; i < a.size(); i++) {
        chk[a[i]]++;
    }
    for(int i = 0; i < a.size(); i++) {
        if(chk[i] == 0) {
            continue;
        }
        ans.push_back({chk[i],i});
    }
    sort(ans.begin(),ans.end(),greater());
    for(int i = 0; i < ans.size(); i++) {
        int num = ans[i].Y;
        if(answer >= ans[i].X) {
            break;
        }
        int sum = 0;
        for(int j = 0; j < a.size()-1; j++) {
            if(a[j] != num && a[j+1] != num) {
                continue;
            }
            if(a[j] == a[j+1]) {
                continue;
            }
            sum++;
            j++;
        }
        if(answer < sum) {
            answer = sum;
        }
    }
    answer *= 2;
    return answer;
}