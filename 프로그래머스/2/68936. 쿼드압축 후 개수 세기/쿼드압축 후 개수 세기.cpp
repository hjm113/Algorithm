#include <string>
#include <vector>
#include <iostream>
using namespace std;
int board[1050][1050];
int chk[2];
void solve(int sx, int ex, int sy, int ey) {
    int chk0 = 0;
    int chk1 = 0;
    for(int i = sx; i < ex; i++) {
        for(int j = sy; j < ey; j++) {
            if(board[i][j] == 1) {
                chk0 = 1;
            }
            if(board[i][j] == 0) {
                chk1 = 1;
            }
        }
    }
    if(chk0 == 0) {
        chk[0]++;
        return;
    }
    else if(chk1 == 0) {
        chk[1]++;
        return;
    }
    else {
        /*
        if(ex-sx == 2 || ey-sy == 2) {
            return;
        }
        */
        solve(sx,(sx+ex)/2,sy,(sy+ey)/2);
        solve(sx,(sx+ex)/2,(sy+ey)/2,ey);
        solve((sx+ex)/2,ex,sy,(sy+ey)/2);
        solve((sx+ex)/2,ex,(sy+ey)/2,ey);
    }
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = arr[i][j];
        }
    }
    solve(0,n,0,n);
    answer.push_back(chk[0]);
    answer.push_back(chk[1]);
    return answer;
}