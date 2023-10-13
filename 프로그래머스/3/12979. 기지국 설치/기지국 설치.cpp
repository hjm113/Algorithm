#include <iostream>
#include <vector>
using namespace std;
vector<int> dat;
int len = 0;
int lst = 0;
int solve(int x) {
}

int solution(int n, vector<int> stations, int w)
{
    len = w;
    lst = n;
    int answer = 0;
    for(int i = 0; i < stations.size(); i++) {
        dat.push_back(stations[i]);
    }
    for(int i = 0; i < dat.size(); i++) {
        //cout << dat[i] << " ";
    }
    /*
    int st = 0;
    int en = 200000000;
    while(st < en) {
        int mid = (st+en)/2;
        if(solve(mid) == 0) {
            st = mid+1;
        }
        else {
            en = mid;
        }
    }
    */
    int len = w*2+1;
    int sum = 0;
    for(int i = 0; i < dat.size(); i++) {
        if(i == 0) {
            int dist = (dat[i]-w)-1;
            if(dist <= 0) {
                continue;
            }
            int used = dist/len;
            if(dist%len != 0) {
                used++;
            }
            sum += used;
            //cout << dist << "asdf\n";
        }
        else {
            int dist = (dat[i]-w)-(dat[i-1]+w)-1;
            if(dist <= 0) {
                continue;
            }
            int used = dist/len;
            if(dist%len != 0) {
                used++;
            }
            //cout << dist << "asdsdff\n";
            sum += used;
        }
        cout << sum << "\n";
    }
    if(dat[dat.size()-1] != lst) {
        int dist = lst-(dat[dat.size()-1]+w);
        if(dist > 0) {
            int used = dist/len;
            if(dist%len != 0) {
                used++;
            }
            sum += used;
        }
    }
    answer = sum;
    return answer;
}