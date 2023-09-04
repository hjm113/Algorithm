#include <string>
#include <vector>
#include <queue>;
using namespace std;
int vis[1000005];
queue<int> q;
int solution(int x, int y, int n) {
    int answer = 0;
    for(int i = 0; i < 1000005; i++) {
        vis[i] = -1;
    }
    vis[x] = 0;
    q.push(x);
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur+n <= 1000000 && vis[cur+n] == -1) {
            vis[cur+n] = vis[cur]+1;
            q.push(cur+n);
        }
        if(cur*2 <= 1000000 && vis[cur*2] == -1) {
            vis[cur*2] = vis[cur]+1;
            q.push(cur*2);
        }
        if(cur*3 <= 1000000 && vis[cur*3] == -1) {
            vis[cur*3] = vis[cur]+1;
            q.push(cur*3);
        }
    }
    answer = vis[y];
    return answer;
}