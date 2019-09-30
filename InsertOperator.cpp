//
//  main.cpp
//  InsertOperator
//
//  Created by 임채빈 on 30/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> v;
int oper[4];
int _min = 1111111111;
int _max = -1111111111;

void dfs(int now, int res){
    if(now == N-1){
        if(res < _min){
            _min = res;
        }
        if(res > _max){
            _max = res;
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        if(oper[i] > 0){
            oper[i]--;
            if(i == 0){
                dfs(now+1, res+v[now+1]);
            }else if(i == 1){
                dfs(now+1, res-v[now+1]);
            }else if(i == 2){
                dfs(now+1, res*v[now+1]);
            }else if(i == 3){
                dfs(now+1, res/v[now+1]);
            }
            oper[i]++;
        }
    }
}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << "start" << endl;
    //입력받기
    cin >> N;
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    for(int i = 0; i < 4; i++){
        int input;
        cin >> input;
        oper[i] = input;
    }
    //함수실행
    dfs(0, v[0]);
    
    cout << _max << "\n" << _min << "\n";
    return 0;
}
