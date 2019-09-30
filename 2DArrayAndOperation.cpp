//
//  main.cpp
//  2Array&Operation
//
//  Created by 임채빈 on 01/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int map[101][101], map_copy[101][101];
int r, c, k;
int r_size = 3, c_size = 3;
int check[101];

void operationR(){
    int _max = 0;
    for(int i= 1; i <= r_size; i++){
        // 1. 원하는 행의 값들을 가져온다.
        vector<int> v, v2;
        for(int j = 1; j <= c_size; j++){
            if(map[i][j] != 0){
                v.push_back(map[i][j]);
                check[map[i][j]]++;
            }else{
                continue;
            }
        }
        // 2. 121 -> 2112로 바꾸는 작업.
        for(int j = 1; j <= 100; j++){
            for(int k = 1; k <= 100; k++){
                if(check[k] == j){
                    v2.push_back(k);
                    v2.push_back(j);
                    if(v2.size() == 100){
                        break;
                    }
                }
            }
            if(v2.size() == 100){
                break;
            }
        }
        if(v2.size() > _max){
            _max = v2.size();
        }
        // 3. 바뀐 값을 map_copy에 넣어준다.
        for(int j = 1; j <= v2.size(); j++){
            map_copy[i][j] = v2[j-1];
        }
        memset(check, 0, sizeof(check));
    }
    // c_size를 변화시켜준다.
    c_size = _max;
    
    //map_copy의 값을 map에 넣어준다.
    memset(map, 0, sizeof(map));
    for(int i = 1; i <= r_size; i++){
        for(int j = 1; j <= c_size; j++){
            map[i][j] = map_copy[i][j];
            map_copy[i][j] = 0;
        }
    }
}

void operationC(){
    int _max = 0;
    for(int j = 1; j <= c_size; j++){
        //1. 원하는 열들의 값을 가져온다.
        vector<int> v, v2;
        for(int i = 1; i <= r_size; i++){
            if(map[i][j] != 0){
                v.push_back(map[i][j]);
                check[map[i][j]]++;
            }else{
                continue;
            }
        }
        //2. 213 -> 112131로 바꾸기.
        for(int i = 1; i <= 100; i++){
            for(int k = 1; k <= 100; k++){
                if(check[k] == i){
                    v2.push_back(k);
                    v2.push_back(i);
                }
                if(v2.size() == 100){
                    break;
                }
            }
            if(v2.size() == 100){
                break;
            }
        }
        if(v2.size() > _max){
            _max = v2.size();
        }
        // 3. 바뀐 값을 map_copy에 넣어준다.
        for(int i = 1; i <= v2.size(); i++){
            map_copy[i][j] = v2[i-1];
        }
        memset(check, 0, sizeof(check));
    }
    // r_size를 변화시켜준다.
    r_size = _max;
    
    //map_copy의 값을 map에 넣어준다.
    memset(map, 0, sizeof(map));
    for(int i = 1; i <= r_size; i++){
        for(int j = 1; j <= c_size; j++){
            map[i][j] = map_copy[i][j];
            map_copy[i][j] = 0;
        }
    }
}







int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    //입력받기
    cin >> r >> c >> k;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> map[i][j];
        }
    }
    int res = 0;
    bool success = false;
    while(res < 101){
        //r행 c열에 k가 있으면, 게임 끝.
        if(map[r][c] == k){
            success = true;
            break;
        }else{
            //행 크기가 열 크기보다 크거나 같으면, R연산
            if(r_size >= c_size){
                operationR();
            }else{ // 열 크기가 행 크기보다 크면, C연산
                operationC();
            }
            
        }
        
        
        res++;
    }
    
    if(success){
        cout << res << endl;
    }else{
        cout << -1 << "\n";
    }
    
    
    return 0;
}
