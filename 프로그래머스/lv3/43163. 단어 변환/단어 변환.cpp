#include <string>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second
int vis[65];
queue <pair<string,int>> q;
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    q.push({begin,60});
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int i = 0; i < words.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < cur.X.size(); j++) {
                if(cur.X[j] != words[i][j]) {
                    cnt++;
                }
            }
            if(cnt == 1) {
                if(vis[i] > 0) {
                    continue;
                }
                if(words[i] == target) {
                    answer = vis[cur.Y] + 1;
                }
                vis[i] = vis[cur.Y] + 1;
                q.push({words[i],i});
            }
        }
    }
    return answer;
}