#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second
vector<pair<int,int>> r;
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int n = routes.size();
    for(int i = 0; i < n; i++) {
        r.push_back({routes[i][0],routes[i][1]});
    }
    sort(r.begin(),r.end());
    int st = r[0].X;
    int en = r[0].Y;
    answer = 1;
    for(int i = 1; i < n; i++) {
        if(r[i].X <= en) {
            if(r[i].Y <= en) {
                en = r[i].Y;
            }
            continue;
        }
        en = r[i].Y;
        answer++;
    }
    return answer;
}