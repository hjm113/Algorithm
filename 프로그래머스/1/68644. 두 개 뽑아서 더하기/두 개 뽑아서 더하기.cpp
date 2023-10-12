#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int num[105];
int chk[1005];
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();
    num[n-1] = 1;
    num[n-2] = 1;
    do{
        int sum = 0;
        for(int i = 0; i < n; i++) {
           if(num[i] == 1) {
               sum += numbers[i];
           } 
        }
        if(chk[sum] == 0) {
            answer.push_back(sum);
            chk[sum] = 1;
        }
    }while(next_permutation(num,num+n));
    sort(answer.begin(),answer.end());
    return answer;
}