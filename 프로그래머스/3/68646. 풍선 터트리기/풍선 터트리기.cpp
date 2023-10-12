#include <string>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int solution(vector<int> a) {
    int answer = 1;
    for(int i = 0; i < a.size(); i++) {
        pq.push({a[i],i});
    }
    int fmx = 1000000005;
    for(int st = 0; st < a.size()-1; st++) {
        while(!pq.empty() && pq.top().Y <= st) {
            pq.pop();
        }
        if(a[st] < fmx || a[st] < pq.top().X) {
            answer++;
        }
        if(fmx > a[st]) {
            fmx = a[st];
        }
    }
    return answer;
}