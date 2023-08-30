#include <vector>
using namespace std;
int ary[200005];
int cnt = 0;
int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    for(int i = 0; i < nums.size(); i++) {
        ary[nums[i]] = 1;
    }
    for(int i = 1; i <= 200000; i++) {
        if(ary[i] == 1) {
            cnt++;
        }
        if(cnt == n/2) {
            break;
        }
    }
    answer = cnt;
    return answer;
}