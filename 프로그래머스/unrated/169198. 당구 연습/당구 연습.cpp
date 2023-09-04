#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int m, int n, int startY, int startX, vector<vector<int>> balls) {
    vector<int> answer;
    for(int i = 0; i < balls.size(); i++) {
        int x = balls[i][1];
        int y = balls[i][0];
        int mxx = max(startX,x);
        int mnx = min(startX,x);
        int mxy = max(startY,y);
        int mny = min(startY,y);
        int mn = 2000000000;
        if(startX != x || (startX == x && startY < y)) {
            double b = (double)mxy/mny+1;
            double a = (double)(mxx-mnx)/b;
            int ans = round(pow((sqrt(pow(mny,2)+pow(a,2))+sqrt(pow(mxy,2)+pow(a*mxy/mny,2))),2));
            if(mn > ans) {
                //cout << ans << " 1\n";
                mn = ans;
            }
        }
        if(startY != y || (startY == y && startX < x)) {
            double b = (double)mxx/mnx+1;
            double a = (double)(mxy-mny)/b;
            double ans = round(pow((sqrt(pow(mnx,2)+pow(a,2))+sqrt(pow(mxx,2)+pow(a*mxx/mnx,2))),2));
            if(mn > ans) {
                //cout << ans << " 2\n";
                mn = ans;
            }
        }
        if(startX != x || (startX == x && startY > y)) {
            mxx = max(startX,x);
            mnx = min(startX,x);
            mxy = max(m-startY,m-y);
            mny = min(m-startY,m-y);
            double b = (double)mxy/mny+1;
            double a = (double)(mxx-mnx)/b;
            double ans = round(pow((sqrt(pow(mny,2)+pow(a,2))+sqrt(pow(mxy,2)+pow(a*mxy/mny,2))),2));
            if(mn > ans) {
                //cout << ans << " 3\n";
                mn = ans;
            }
        }
        if(startY != y || (startY == y && startX > x)) {
            mxx = max(n-startX,n-x);
            mnx = min(n-startX,n-x);
            mxy = max(startY,y);
            mny = min(startY,y);
            double b = (double)mxx/mnx+1;
            double a = (double)(mxy-mny)/b;
            double ans = round(pow((sqrt(pow(mnx,2)+pow(a,2))+sqrt(pow(mxx,2)+pow(a*mxx/mnx,2))),2));
            if(mn > ans) {
                //cout << ans << " 4\n";
                mn = ans;
            }
        }
        answer.push_back(mn);
        //cout << mn << "\n";
    }
    return answer;
}