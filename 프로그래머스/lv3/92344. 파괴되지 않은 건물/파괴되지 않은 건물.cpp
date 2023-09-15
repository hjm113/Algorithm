#include <string>
#include <vector>
#include <iostream>
using namespace std;
int tmp[1005][1005];
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    for(int i = 0; i < skill.size(); i++) {
        int t = skill[i][0];
        int sx = skill[i][1];
        int sy = skill[i][2];
        int ex = skill[i][3];
        int ey = skill[i][4];
        int d = skill[i][5];
        if(t == 1) {
            tmp[sx][sy] += -d;
            tmp[ex+1][sy] += d;
            tmp[sx][ey+1] += d;
            tmp[ex+1][ey+1] += -d;
        }
        else {
            tmp[sx][sy] += d;
            tmp[ex+1][sy] += -d;
            tmp[sx][ey+1] += -d;
            tmp[ex+1][ey+1] += d;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            tmp[i][j+1] += tmp[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            tmp[j+1][i] += tmp[j][i];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            board[i][j] += tmp[i][j];
        }
     }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] > 0) {
                answer++;
            }
        }
    }
    return answer;
}