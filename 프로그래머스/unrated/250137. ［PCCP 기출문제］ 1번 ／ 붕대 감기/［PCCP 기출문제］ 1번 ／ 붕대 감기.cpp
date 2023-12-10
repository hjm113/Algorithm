#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int en = attacks[attacks.size()-1][0];
    int at = 0;
    int suc = 0;
    int hp = health;
    for(int i = 0 ; i <= en; i++) {
        if(i == attacks[at][0]) {
            hp -= attacks[at][1];
            suc = 0;
            at++;
            if(hp <= 0) {
                answer = -1;
                return answer;
            }
            //cout << hp << " attack" << "\n";
            continue;
        }
        suc++;
        hp += bandage[1];
        if(suc == bandage[0]) {
            hp += bandage[2];
            suc = 0;
        }
        if(hp >= health) {
            hp = health;
        }
        //cout << hp << "\n";
    }
    answer = hp;
    return answer;
}