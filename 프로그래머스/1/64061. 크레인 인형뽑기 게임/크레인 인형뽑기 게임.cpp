#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;
deque<int> dq[35];
deque<int> box;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0) {
                continue;
            }
            dq[j+1].push_back(board[i][j]);
        }
    }
    for(int i = 0; i < moves.size(); i++) {
        int num = moves[i];
        if(dq[num].empty()) {
            continue;
        }
        if(!box.empty() && box.back() == dq[num].back()) {
            answer += 2;
            box.pop_back();
        }
        else {
            box.push_back(dq[num].back());
        }
        dq[num].pop_back();
    }
    return answer;
}