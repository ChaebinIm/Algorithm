//
//  main.cpp
//  HomeKeepingService
//
//  Created by 임채빈 on 18/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int N, M;
int map[20][20];
bool visited[20][20];
int res = 0;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};
queue<pair<int,int>> q, q_copy;


int operate(){
    int cnt = 0;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(map[r][c] == 1){
            cnt++;
        }
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < N && nc >= 0 && nc < N){
                if(!visited[nr][nc]){
                    visited[nr][nc] = true;
                    q_copy.push({nr, nc});
                }
            }
        }
    }
    q = q_copy;
    while(!q_copy.empty()){
        q_copy.pop();
    }
    return cnt;
}





int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    int _test;
    cin >> _test;
    for(int test = 1; test <= _test; test++){
        res = 0;
        // input
        cin >> N >> M;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> map[i][j];
            }
        }
        // (0,0) ~ (N-1, N-1)까지 체크한다.
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                // k = 1 ~ 2N1-1까지 본다
                q.push({i, j});
                visited[i][j] = true;
                int base = 0;
                for(int k = 1; k < 2*N; k++){
                    
                    int cost = k*k+(k-1)*(k-1);
                    base = base + operate();
                    int sales = M * base;
                    int profit = sales - cost;
                    int home = sales/M;
                    if(profit >= 0){
                        if(res < home){
                            res = home;
                        }
                    }
                }
                memset(visited, false, sizeof(visited));
                while(!q.empty()){
                    q.pop();
                }
            }
        }
        memset(map, 0, sizeof(map));
        cout << "#" << test << " " << res << "\n";
    }
    return 0;
}
