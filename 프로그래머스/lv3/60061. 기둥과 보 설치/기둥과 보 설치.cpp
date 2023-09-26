#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int board[105][105][4];
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(int i = 0; i < build_frame.size(); i++) {
        int y = build_frame[i][0];
        int x = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if(a == 0) {
            if(b == 1) {
                if(x == 0 || board[x][y][1] == 1 || board[x][y][2] == 1 || board[x][y][3] == 1) {
                    board[x][y][0] = 1;
                    board[x+1][y][2] = 1;
                }
            }
            else {
                if(board[x+1][y][3] == 1) {
                    if((board[x+1][y][1] == 0 || board[x+1][y+1][3] == 0) && board[x+1][y+1][2] == 0) {
                        continue;
                    }
                }
                if(board[x+1][y][1] == 1) {
                    if((board[x+1][y][3] == 0 || board[x+1][y-1][1] == 0) && board[x+1][y-1][2] == 0) {
                        continue;
                    }
                }
                if(board[x+1][y][0] == 1) {
                    if(board[x+1][y][1] == 0 && board[x+1][y][3] == 0) {
                        continue;
                    }
                }
                board[x][y][0] = 0;
                board[x+1][y][2] = 0;
            }
        }
        else {
            if(b == 1) {
                if(board[x][y][2] == 1 || board[x][y+1][2] == 1 || (board[x][y][1] == 1 && board[x][y+1][3] == 1)) {
                    board[x][y][3] = 1;
                    board[x][y+1][1] = 1;
                }
            }
            else {
                if(board[x][y+1][3] == 1) {
                    if(board[x][y+1][2] == 0 && board[x][y+2][2] == 0) {
                        continue;
                    }
                }
                if(board[x][y][1] == 1) {
                    if(board[x][y][2] == 0 && board[x][y-1][2] == 0) {
                        continue;
                    }
                }
                if(board[x][y][0] == 1) {
                    if(board[x][y][1] == 0 && board[x][y][2] == 0) {
                        continue;
                    }
                }
                if(board[x][y+1][0] == 1) {
                    if(board[x][y+1][3] == 0 && board[x][y+1][2] == 0) {
                        continue;
                    }
                }
                board[x][y][3] = 0;
                board[x][y+1][1] = 0;
            }
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(board[i][j][0] == 1) {
                answer.push_back({j,i,0});
            }
            if(board[i][j][3] == 1) {
                answer.push_back({j,i,1});
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}