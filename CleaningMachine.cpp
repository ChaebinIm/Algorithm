//
//  main.cpp
//  CleaningMachine
//
//  Created by 임채빈 on 19/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
using namespace std;

void dfs1();
void dfs2();
int M, N;
int map[51][51];
queue<pair<int,int>> q;
int r, c; // r,c는 현재 위치.
int dir;   //dir은 현재 보고있는 방향. 0 : 북, 1 : 동, 2 : 남, 3 : 서
int cnt = 0; //cnt는 회전한 수를 의미.

//searching은 현재 보고 있는 방향의 왼쪽 방향에 청소할 곳이 있는지 보는 함수. 있다면 true 출력. 없으면 false 출력.
bool searching(){
    int flag = false;
    if(dir == 0){ // 현재 보는 방향이 북쪽이라면,
        flag = (map[r][c-1] == 0);
    }else if(dir == 1){ // 현재 보는 방향이 동쪽이라면,
        flag = (map[r-1][c] == 0);
    }else if(dir == 2){ // 현재 보는 방향이 남쪽이라면,
        flag = (map[r][c+1] == 0);
    }else if(dir == 3){ // 현재 보는 방향이 서쪽이라면,
        flag = (map[r+1][c] == 0);
    }
    return flag;
}

//방향을 바꾸는 함수.
void changeDir(){
    switch(dir){
        case 0 : dir = 3;break;
        case 1 : dir = 0;break;
        case 2 : dir = 1;break;
        case 3 : dir = 2;break;
    }
    cnt++;
}

// 현재 보는 방향으로 한칸 이동하는 함수.
void moveOneStep(){
    if(dir == 0){
        r = r - 1;
    }else if(dir == 1){
        c = c + 1;
    }else if(dir == 2){
        r = r + 1;
    }else if(dir == 3){
        c = c - 1;
    }
    cnt = 0;
}

// 후진 가능한지 체크여부. 후진 불가능하면 true 출력.
bool rearPossible(){
    bool flag = false;
    if(dir == 0){
        flag = (map[r+1][c] == 1);
    }else if(dir == 1){
        flag = (map[r][c-1] == 1);
    }else if(dir == 2){
        flag = (map[r-1][c] == 1);
    }else if(dir == 3){
        flag = (map[r][c+1] == 1);
    }
    return flag;
}

void dfs1(){
    if(map[r][c] == 0){
        map[r][c] = 2; //2는 청소 했음을 의미.
    }
    dfs2();
    
}

void dfs2(){
    if(searching()){
        changeDir();
        moveOneStep();
        dfs1();
    }else if(cnt == 4 && rearPossible()){
        return;
    }else if(cnt == 4){
        if(dir == 0){
            r = r + 1;
        }else if(dir == 1){
            c = c - 1;
        }else if(dir == 2){
            r = r - 1;
        }else if(dir == 3){
            c = c + 1;
        }
        cnt = 0;
        dfs2();
    }else{
        changeDir();
        dfs2();
    }
    
    
}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << "start" << endl;
    // 입력받기
    cin >> M >> N;
    //로봇 위치, 보고 있는 방향 입력받기.
    cin >> r >> c >> dir;
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    
    
    dfs1();
    
    int res = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 2)
                res++;
        }
    }
    
    cout << res << "\n";
    
    
    return 0;
}
