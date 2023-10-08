#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
using namespace std;
vector<tuple<string,int,int>> ans;
vector<string> solution(vector<string> files) {
    vector<string> answer;
    for(int i = 0; i < files.size(); i++) {
        string head = "";
        string num = "";
        int chk = 0;
        for(int j = 0; j < files[i].size(); j++) {
            if(files[i][j] >= '0' && files[i][j] <= '9') {
                chk = 1;
                num += files[i][j];
            }
            else {
                if(chk == 1) {
                    break;
                }
                head += tolower(files[i][j]);
            }
        }
        ans.push_back({head,stoi(num),i});
    }
    sort(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++) {
        string a;
        int b,c;
        tie(a,b,c) = ans[i];
        answer.push_back(files[c]);
    }
    
    return answer;
}