#include <string>
#include <vector>
#include <iostream>
using namespace std;
int ary[105][105];
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int n1 = arr1.size();
    int m1 = arr1[0].size();
    int m2 = arr2[0].size();
    for(int i = 0; i < n1; i++) {
        vector<int> ans;
        for(int j = 0; j < m2; j++) {
            int sum = 0;
            for(int k = 0; k < m1; k++) {
                sum += arr1[i][k]*arr2[k][j];
            }
            ans.push_back(sum);
        }
        answer.push_back(ans);
    }
    return answer;
}