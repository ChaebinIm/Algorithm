//
//  main.cpp
//  N_Queen
//
//  Created by 임채빈 on 11/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int N;
int res = 0;
int arr[15];

// arr[cnt][n]에 퀸을 넣을 수 있는가? 를 체크하는 함수.
bool condition(int cnt, int n){
    bool result = true;
    for(int i = 0; i < cnt; i++){
        if(arr[i] == n || cnt - i == abs(n - arr[i])){
            result = false;
            break;
        }
    }
    return result;
}

void dp(int cnt){
    if(cnt == N){
        res++;
    }else{
        for(int i = 0; i < N; i++){
            if(condition(cnt, i)){ // 여기서 cnt는 cnt번째 행을 의미.
                // (arr[cnt] = i)는 cnt번째 행의 i번째 열에 퀸을 배치한다는 것을 의미.
                arr[cnt] = i;
                dp(cnt + 1);
            }
        }
    }
}



int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> N;
    dp(0);
    cout << res << "\n";
    return 0;
}
