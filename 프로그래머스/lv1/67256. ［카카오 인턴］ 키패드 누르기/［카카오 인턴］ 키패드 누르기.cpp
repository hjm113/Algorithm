#include <string>
#include <vector>
#include <iostream>
#define X first
#define Y second
using namespace std;
pair<int,int> pos[15];
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int cnt = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            pos[cnt] = {i,j};
            cnt++;
        }
    }
    pos[0] = {3,1};
    int rx = 3;
    int ry = 2;
    int lx = 3;
    int ly = 0;
    for(int i = 0; i < numbers.size(); i++) {
        //cout << rx << " " << ry << " " << lx << " " << ly << "\n";
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            lx = pos[numbers[i]].X;
            ly = pos[numbers[i]].Y;
            continue;
        }
        if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            rx = pos[numbers[i]].X;
            ry = pos[numbers[i]].Y;
            continue;
        }
        int x = pos[numbers[i]].X;
        int y = pos[numbers[i]].Y;
        int rdist = abs(rx-x)+abs(ry-y);
        int ldist = abs(lx-x)+abs(ly-y);
        //cout << ldist << " " << rdist << "\n";
        if(ldist < rdist) {
            answer += 'L';
            lx = pos[numbers[i]].X;
            ly = pos[numbers[i]].Y;
        }
        else if(rdist < ldist) {
            answer += 'R';
            rx = pos[numbers[i]].X;
            ry = pos[numbers[i]].Y;
        }
        else {
            if(hand == "right") {
                answer += 'R';
                rx = pos[numbers[i]].X;
                ry = pos[numbers[i]].Y;
            }
            else {
                answer += 'L';
                lx = pos[numbers[i]].X;
                ly = pos[numbers[i]].Y;
            }
        }
    }
    return answer;
}