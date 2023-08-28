#include <string>
#include <vector>

using namespace std;
vector<int> l;
vector<int> s;
int mx1 = 0;
int mx2 = 0;
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int n = sizes.size();
    for(int i = 0; i < n; i++) {
        if(sizes[i][0] > sizes[i][1]) {
            l.push_back(sizes[i][0]);
            s.push_back(sizes[i][1]);
        }
        else {
            l.push_back(sizes[i][1]);
            s.push_back(sizes[i][0]);
        }
    }
    for(int i = 0; i < n; i++) {
        if(l[i] > mx1) {
            mx1 = l[i];
        }
        if(s[i] > mx2) {
            mx2 = s[i];
        }
    }
    answer = mx1 * mx2;
    return answer;
}