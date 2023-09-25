#include <string>
#include <vector>
#include <iostream>
using namespace std;
int nlock[100][100];
int tlock[100][100];
void rotate(vector<vector<int>> &key) {
    int n = key.size();
    int tmp[25][25] = {};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp[i][j] = key[n-1-j][i];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            key[i][j] = tmp[i][j];
        }
    }
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int n = lock.size();
    int m = key.size();
    for(int i = 0; i <= 60; i++) {
        for(int j = 0; j <= 60; j++) {
            nlock[i][j] = 2;
            tlock[i][j] = nlock[i][j];
        }
    }
    
    for(int i = 20; i < 20+n; i++) {
        for(int j = 20; j < 20+n; j++) {
            nlock[i][j] = lock[i-20][j-20];
            tlock[i][j] = nlock[i][j];
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 60; j++) {
            for(int k = 0; k < 60; k++) {
                for(int r = 0; r < m; r++) {
                    for(int w = 0; w < m; w++) {
                        if(nlock[j+r][k+w] == 2) {
                            continue;
                        }
                        if(key[r][w] == 1) {
                            if(nlock[j+r][k+w] == 0) {
                                nlock[j+r][k+w] = 1;
                            }
                            else {
                                nlock[j+r][k+w] = 0;
                            }
                        }
                    }
                }
                int chk = 0;
                for(int r = 20; r < 20+n; r++) {
                    for(int w = 20; w < 20+n; w++) {
                        if(nlock[r][w] != 1) {
                            chk = 1;
                        }
                    }
                }
                if(chk == 0) {
                    cout << i << "\n";
                    answer = true;
                    return answer;
                }
                for(int r = 0; r < 60; r++) {
                    for(int w = 0; w < 60; w++) {
                        nlock[r][w] = tlock[r][w];
                    }
                }
            }
        }
        rotate(key);
    }
    return answer;
}