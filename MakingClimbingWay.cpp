//
//  main.cpp
//  ClimbingWay
//
//  Created by 임채빈 on 19/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int T;
int res = 0;
int map[8][8], map_init[8][8];
int N, K;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
vector<pair<int,int>> v;
queue<pair<int,int>> q, q_copy;;


void bfs(){
    bool visited[8][8];
    memset(visited, false, sizeof(visited));
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < N && nc >= 0 && nc < N && map[nr][nc] < map[r][c]){
                if(!visited[nr][nc]){
                    visited[nr][nc] = true;
                    q_copy.push({nr, nc});
                }
            }
        }
    }
    memset(visited, false, sizeof(visited));
    q = q_copy;
    while(!q_copy.empty()){
        q_copy.pop();
    }
}




int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> T;
    for(int test = 1; test <= T; test++){
        res = 0;
        // input
        cin >> N >> K;
        int _max = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> map[i][j];
                // 가장 높은 봉우리의 위치를 vector에 집어넣기.
                if(map[i][j] > _max){
                    v.clear();
                    _max = map[i][j];
                    v.push_back({i, j});
                }else if(map[i][j] == _max){
                    v.push_back({i, j});
                }
            }
        }
        // 전체 봉우리를 K만큼 자르고 BFS 완전탐색하기.
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < v.size(); k++){
                    for(int a = 1; a <= K; a++){
                        map[i][j] = map[i][j] - a;
                        // 1. 시작 봉우리 위치 정하기.
                        int r = v[k].first;
                        int c = v[k].second;
                        if(r == i && c == j){
                            map[i][j] = map[i][j] + a;
                            continue;
                        }
                        // 2. 시작 봉우리부터 BFS 탐색.
                        q.push({r, c});
                        int cnt = 0;
                        while(!q.empty()){
                            bfs();
                            cnt++;
                        }
                        if(cnt > res){
                            res = cnt;
                        }
                        map[i][j] = map[i][j] + a;
                    }
                }
            }
        }
        
        cout << "#" << test << " " << res << "\n";
    }
    return 0;
}
