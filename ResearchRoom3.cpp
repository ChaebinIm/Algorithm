//
//  main.cpp
//  ResearchRoom3
//
//  Created by 임채빈 on 17/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int map[50][50], map_init[50][50];
bool visited[50][50], visited_init[50][50];
vector<pair<int,int>> v;
bool visited_dp[9];
int arr[9];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
queue<pair<int,int>> q, q_copy;
int _min = 99999999;

void bfs(){
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        visited[r][c] = true;
        q.pop();
        map[r][c] = 2;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < N && nc >= 0 && nc < N){
                if(!visited[nr][nc]){
                    visited[nr][nc] = true;
                    q_copy.push(make_pair(nr,nc));
                }
            }
        }
    }
    q = q_copy;
    while(!q_copy.empty()){
        q_copy.pop();
    }
}


void dp(int cnt){
    if(cnt == M+1){
        // 바이러스 넣을 위치를 queue에 push
        for(int i = 1; i <= M; i++){
            q.push(make_pair(v[arr[i]].first,v[arr[i]].second));
        }
        int cnt = 0;
        int flag = 1;
        while(!q.empty() && flag){
            flag = 0;
            bfs();
            cnt++;
            // q의 내용이 전부 이미 바이러스라면? 이는 끝난것!
            int _size = q.size();
            for(int i = 0; i < _size; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(map[r][c] != 2){
                    flag++;
                }
                q_copy.push(make_pair(r,c));
            }
            q = q_copy;
            while(!q_copy.empty()){
                q_copy.pop();
            }
        }
        if(flag == 0){
            while(!q.empty()){
                q.pop();
            }
        }
        bool success = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j] == 0){
                    success = false;
                    break;
                }
            }
            if(!success){
                break;
            }
        }
        if(cnt < _min && success){
            _min = cnt;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                visited[i][j] = visited_init[i][j];
                map[i][j] = map_init[i][j];
            }
        }
    }else{
        // 모든 경우의 수 고려.
        for(int i = arr[cnt-1]; i < v.size(); i++){
            if(!visited_dp[i]){
                visited_dp[i] = true;
                arr[cnt] = i;
                dp(cnt+1);
                visited_dp[i] = false;
            }
        }
    }
    
    
    
    
    
    
}




int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    // input
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            map_init[i][j] = map[i][j];
            if(map[i][j] == 2){
                v.push_back(make_pair(i,j));
                visited[i][j] = true;
            }else if(map[i][j] != 0){
                visited[i][j] = true;
                visited_init[i][j] = true;
            }
        }
    }
    
    // 모든 경우의 수 고려.
    dp(1);
    if(_min == 99999999){
        cout << -1 << "\n";
    }else{
        cout << _min-1 << "\n";
    }
    return 0;
}
