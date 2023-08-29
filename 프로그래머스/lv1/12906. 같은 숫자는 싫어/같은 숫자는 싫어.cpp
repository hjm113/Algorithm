#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int a = arr[0];
    answer.push_back(a);
    for(int i = 0; i < arr.size(); i++) {
        if(a != arr[i]) {
            answer.push_back(arr[i]);
            a = arr[i];
        }
    }
    return answer;
}