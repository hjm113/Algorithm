#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i = 0; i < new_id.length(); i++) {
        if(new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] += 32;
        }
    }
    string tmp = "";
    for(int i = 0; i < new_id.length(); i++) {
        if(new_id[i] >= 'a' && new_id[i] <= 'z') {
            tmp += new_id[i];
        }
        if(new_id[i] >= '0' && new_id[i] <= '9') {
            tmp += new_id[i];
        }
        if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            tmp += new_id[i];
        }
    }
    new_id = tmp;
    tmp = "";
    for(int i = 0; i < new_id.length(); i++) {
        tmp += new_id[i];
        if(new_id[i] == '.') {
            int idx = i+1;
            while(new_id[idx] == '.') {
                idx++;
            }
            i = idx-1;
        }
    }
    new_id = tmp;
    if(new_id[0] == '.') {
        new_id = new_id.substr(1);
    }
    if(new_id[new_id.length()-1] == '.') {
        new_id = new_id.substr(0,new_id.length()-1);
    }
    if(new_id == "") {
        new_id = "a";
    }
    new_id = new_id.substr(0,15);
    if(new_id[new_id.length()-1] == '.') {
        new_id = new_id.substr(0,new_id.length()-1);
    }
    if(new_id.length() == 2) {
        new_id += new_id[1];
    }
    if(new_id.length() == 1) {
        new_id += new_id[0];
        new_id += new_id[0];
    }
    answer = new_id;
    return answer;
}