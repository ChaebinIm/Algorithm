//
//  main.cpp
//  괄호추가하기
//
//  Created by 임채빈 on 15/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> v;
vector<char> v_oper;
int _max = -9876543210;
// operate는 연산을 하는 함수.
int operate(int a, int b, char c){
    int res = 0;
    if(c == '+'){
        res = a + b;
    }else if(c == '-'){
        res = a - b;
    }else if(c == '*'){
        res = a * b;
    }
    return res;
}

void dp(int now, int sum){
    if(now >= v.size()-1){
        if(sum > _max){
            _max = sum;
        }
        return;
    }
    // 지금(now)부터 2개의 수를 보도록 하겠다.
    if(now + 2 < N/2+1){
        int first = sum;
        int second = v[now+1];
        int third = v[now+2];
        char op_first = v_oper[now];
        char op_second = v_oper[now+1];
        // 뒤의 2개를 괄호를 묶는 경우.
        dp(now + 2, operate(first, operate(second,third, op_second), op_first));
        // 뒤의 2개의 괄호를 묶지 않는 경우.
        dp(now + 1, operate(first, second, op_first));
    }else{
        int first = sum;
        int second = v[now+1];
        char op_first = v_oper[now];
        dp(now + 1, operate(first, second, op_first));
    }
}

int main(int argc, const char * argv[]) {
    cout << "Start" << endl;
    // input
    cin >> N;
    for(int i = 0; i < N; i++){
        char input;
        cin >> input;
        if(i%2 == 0){
            v.push_back(input - '0');
        }else{
            v_oper.push_back(input);
        }
    }
    
    dp(0, v[0]);
    
    cout << _max << endl;
    
    return 0;
}
