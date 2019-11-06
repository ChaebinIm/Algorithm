//
//  main.cpp
//  ContainerLoss
//
//  Created by 임채빈 on 06/11/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
string s;

// 문자열을 쪼개는 Split함수.
vector<string> Ssplit(string s, char c){
    vector<string> v;
    int check = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == c){
            v.push_back(s.substr(check, i - check));
            check = i+1;
        }
    }
    v.push_back(s.substr(check, s.length()-check));
    return v;
}

// String '1234'를 int 1234로 바꾸는 함수
int StoI(string s){
    int res_sub = 0;
    int unit = 1;
    for(int i = s.length()-1; i >= 0; i--, unit = unit * 10){
        res_sub += unit * (s[i]-48);
    }
    return res_sub;
}





int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> s;
    vector<string> v = Ssplit(s, '-');
    vector<int> res;
    for(int i = 0; i < v.size(); i++){
        string now = v[i];
        vector<string> v_sub = Ssplit(now, '+');
        int res_sub = 0;
        for(int j = 0; j < v_sub.size(); j++){
            res_sub += StoI(v_sub[j]);
        }
        res.push_back(res_sub);
    }
    int result = res[0];
    for(int i = 1; i < res.size(); i++){
        result -= res[i];
    }
    cout << result << endl;
    return 0;
}
