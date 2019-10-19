//
//  main.cpp
//  ProtectingFilm
//
//  Created by 임채빈 on 19/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int T, D, W, K;
int res;
int map[13][20], map_init[13][20];
bool visited[13];
int arr[14] = {-1, };
// fix는 값을 바꿔주는 함수
void fix(int d, int value){
    for(int i = 0; i < W; i++){
        map[d][i] = value;
    }
}

// initialize는 원래대로 box를 초기화해주는 함수.
void initialize(int d){
    for(int i = 0; i < W; i++){
        map[d][i] = map_init[d][i];
    }
}


// check는 현재 박스 통과여부를 확인하는 함수
bool check(){
    bool sub_res[20];
    memset(sub_res, false, sizeof(sub_res));
    for(int i = 0; i < W; i++){
        int cnt = 1;
        int obj = map[0][i];
        for(int j = 1; j < D; j++){
            int now = map[j][i];
            if(now == obj){
                cnt++;
            }else{
                obj = now;
                cnt = 1;
            }
            if(cnt == K){
                sub_res[i] = true;
                break;
            }
        }
    }
    bool res = true;
    for(int i = 0; i < W; i++){
        if(!sub_res[i]){
            res = false;
            break;
        }
    }
    return res;
}

void dp(int cnt, int pur){
    if(cnt == pur+1){
        for(int i = 1; i <= pur; i++){
            fix(arr[i], 0);
        }
        bool _res = check();
        for(int i = 1; i <= pur; i++){
            initialize(arr[i]);
        }
        if(_res){
            res = pur;
        }
        for(int i = 1; i <= pur; i++){
            fix(arr[i], 1);
        }
        _res = check();
        for(int i = 1; i <= pur; i++){
            initialize(arr[i]);
        }
        if(_res){
            res = pur;
        }
    }
    {
        for(int i = arr[cnt-1]+1; i < D; i++){
            if(!visited[i]){
                visited[i] = true;
                arr[cnt] = i;
                dp(cnt+1, pur);
                visited[i] = false;
            }
        }
        
    }
    
}





int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> T;
    for(int test = 1; test <= T; test++){
        res = 0;
        // input
        cin >> D >> W >> K;
        for(int i = 0; i < D; i++){
            for(int j = 0; j < W; j++){
                cin >> map[i][j];
                map_init[i][j] = map[i][j];
            }
        }
        bool _res = check();
        if(_res){
            cout << "#" << test << " " << 0 << "\n";
            continue;
        }
        // 1 ~ D개륿 변경함으로써 통과가 가능한지 체크
        for(int i = 1; i <= D; i++){
            dp(1, i);
            if(res != 0){
                break;
            }
        }
        
        cout << "#" << test << " " << res << "\n";
    }
    return 0;
}
