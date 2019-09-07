//
//  main.cpp
//  Kakao_2
//
//  Created by 임채빈 on 07/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
// 문제 : 괄호가 주어졌을 때, 이를 열고 닫는 것이 완전하게 만드는 것.

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string u = "", v = "";



bool isCorrect(string s){
    int o = 0, x = 0;
    bool result = true;
    for(int i = 0; i < s.size(); i++){
        if(s.at(i)=='('){
            o++;
        }else if(s.at(i)==')'){
            x++;
        }
        if(o < x){
            result = false;
            break;
        }
    }
    return result;
}


string devision(string s){
    if(s == "") return s;
    //균형잡힌 문자열 _u, _v로 분리하는 과정
    int i = 0;
    int open = 0, close = 0;
    string _u = "", _v = "";
    while(!(open != 0 && close != 0 && open == close)){
        _u = _u + s.at(i);
        if(s.at(i) == '('){
            open++;
        }else{
            close++;
        }
        i++;
    }
    _v = s.substr(i, s.size()-i);
    
    // 올바른 괄호 문자열인지 체크
    if(isCorrect(_u)){
        return _u + devision(_v);
    }else{
        string _s = "(";
        _s = _s + devision(_v) + ")";
        _u = _u.substr(1, _u.size()-2);
        string _u2 = "";
        for(int i = 0; i < _u.size(); i++){
            if(_u.at(i) == '('){
                _u2 = _u2 + ')';
            }else{
                _u2 = _u2 + '(';
            }
        }
        _s = _s + _u2;
        return _s;
    }
    return s;
}





string solution(string s) {
    string answer = "";
    if(s == "") return s;
    answer = devision(s);
    return answer;
}



int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    string s;
    cin >> s;
    cout << solution(s) << endl;
    
    
    
    return 0;
}
