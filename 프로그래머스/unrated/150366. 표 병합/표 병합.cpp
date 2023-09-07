#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <set>
#define X first
#define Y second
using namespace std;
string board[55][55];
int mer[55][55];
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(int j = 1; j <= 50; j++) {
        for(int k = 1; k <= 50; k++) {
            mer[j][k] = (j*50)+k;
        }
    }
    for(int i = 0; i < commands.size(); i++) {
        vector<string> tmp;
        string word = "";
        for(int j = 0; j < commands[i].length(); j++) {
            if(commands[i][j] == ' ') {
                tmp.push_back(word);
                word = "";
                continue;
            }
            word += commands[i][j];
            if(j == commands[i].length()-1) {
                tmp.push_back(word);
            }
        }
        /*
        for(int i = 0; i < tmp.size(); i++) {
            cout << tmp[i] << " ";
        }
        cout << "\n";
        */
        if(tmp[0] == "UPDATE") {
            if(tmp.size() == 4) {
                int x = stoi(tmp[1]);
                int y = stoi(tmp[2]);
                int a = mer[x][y];
                for(int j = 1; j <= 50; j++) {
                    for(int k = 1; k <= 50; k++) {
                        if(mer[j][k] == a) {
                            board[j][k] = tmp[3];
                        }
                    }
                }
            }
            if(tmp.size() == 3) {
                for(int j = 1; j <= 50; j++) {
                    for(int k = 1; k <= 50; k++) {
                        if(board[j][k] == tmp[1]) {
                            board[j][k] = tmp[2];
                        }
                    }
                }
            }
        }
        else if(tmp[0] == "MERGE") {
            int x = stoi(tmp[1]);
            int y = stoi(tmp[2]);
            int nx = stoi(tmp[3]);
            int ny = stoi(tmp[4]);
            if(x == nx && y == ny) {
                continue;
            }
            int a = mer[x][y];
            int b = mer[nx][ny];
            for(int j = 1; j <= 50; j++) {
                for(int k = 1; k <= 50; k++) {
                    if(mer[j][k] == b) {
                        mer[j][k] = a;
                    }
                }
            }
            if(board[x][y] == "") {
                for(int j = 1; j <= 50; j++) {
                    for(int k = 1; k <= 50; k++) {
                        if(mer[j][k] == a) {
                            board[j][k] = board[nx][ny];
                        }
                    }
                }
            }
            else {
                for(int j = 1; j <= 50; j++) {
                    for(int k = 1; k <= 50; k++) {
                        if(mer[j][k] == a) {
                            board[j][k] = board[x][y];
                        }
                    }
                }
            }
        }
        else if(tmp[0] == "UNMERGE") {
            int x = stoi(tmp[1]);
            int y = stoi(tmp[2]);
            int a = mer[x][y];
            for(int j = 1; j <= 50; j++) {
                for(int k = 1; k <= 50; k++) {
                    if(j == x && k == y) {
                        mer[j][k] = (j*50)+k;
                        continue;
                    }
                    if(mer[j][k] == a) {
                        board[j][k] = "";
                        mer[j][k] = (j*50)+k;
                    }
                }
            }
        }
        else if(tmp[0] == "PRINT") {
            int x = stoi(tmp[1]);
            int y = stoi(tmp[2]);
            if(board[x][y] == "") {
                answer.push_back("EMPTY");
            }
            else {
                answer.push_back(board[x][y]);
            }
        }
        /*
        for(int j = 1; j <= 5; j++) {
            for(int k = 1; k <= 5; k++) {
                cout << board[j][k] << " ";
            }
            cout << "\n";
        }
        */
        
    }

    return answer;
}