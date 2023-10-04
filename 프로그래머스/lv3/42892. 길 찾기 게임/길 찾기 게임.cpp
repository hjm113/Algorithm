#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#define X first
#define Y second
using namespace std;
int dir[10005][2];
int ad[10005];
vector<tuple<int,int,int>> tree;
vector<int> ans1;
vector<int> ans2;
void add(int parent, int child) {
    int px,py,pnum;
    tie(py,px,pnum) = tree[parent];
    int cx,cy,cnum;
    tie(cy,cx,cnum) = tree[child];
    if(px > cx) {
        if(dir[pnum][0] == 0) {
            dir[pnum][0] = cnum;
        }
        else {
            add(ad[dir[pnum][0]],ad[cnum]);
        }
    }
    else {
        if(dir[pnum][1] == 0) {
            dir[pnum][1] = cnum;
        }
        else {
            add(ad[dir[pnum][1]],ad[cnum]);
        }
    }
}

void pre(int cur) {
    ans1.push_back(cur);
    if(dir[cur][0] != 0) {
        pre(dir[cur][0]);
    }
    if(dir[cur][1] != 0) {
        pre(dir[cur][1]);
    }
}
void post(int cur) {
    if(dir[cur][0] != 0) {
        post(dir[cur][0]);
    }
    if(dir[cur][1] != 0) {
        post(dir[cur][1]);
    }
    ans2.push_back(cur);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for(int i = 0; i < nodeinfo.size(); i++) {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        tree.push_back({y,x,i+1});
    }
    sort(tree.begin(),tree.end(),greater());
    int tmp1,tmp2,st;
    tie(tmp1,tmp2,st) = tree[0];
    for(int i = 0; i < tree.size(); i++) {
        int a,b,c;
        tie(a,b,c) = tree[i];
        ad[c] = i;
    }
    for(int i = 1; i < tree.size(); i++) {
        int a,b,c;
        tie(a,b,c) = tree[i];
        add(0,i);
    }
    pre(st);
    post(st);
    answer.push_back(ans1);
    answer.push_back(ans2);
    return answer;
}