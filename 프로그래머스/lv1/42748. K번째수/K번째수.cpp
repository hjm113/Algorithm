#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++) {
        vector<int> ans;
        int st = commands[i][0];
        int en = commands[i][1];
        int idx = commands[i][2];
        for(int j = st-1; j < en; j++) {
            ans.push_back(array[j]);
        }
        sort(ans.begin(),ans.end());
        answer.push_back(ans[idx-1]);
    }
    return answer;
}