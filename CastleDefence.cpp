//
//  main.cpp
//  CastleDefence
//
//  Created by 임채빈 on 15/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, M, D;
int map[16][16], map_copy[16][16];
bool visited2[15][15];
int arrow[4]; // arrow는 궁수 각각의 위치를 나타냄.
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
queue<pair<int,int>> q, q_copy;
queue<pair<int,int>> res;
int _max = 0;


pair<int,int> bfs(int r, int c){
    q.push(make_pair(r, c));
    int cnt = 0;
    while(res.empty() && cnt <= D){
        while(!q.empty()){
            int _r = q.front().first;
            int _c = q.front().second;
            q.pop();
            if(map[_r][_c] == 1){
                res.push(make_pair(_r, _c));
            }
            for(int i = 0; i < 4; i++){
                int nr = _r + dr[i];
                int nc = _c + dc[i];
                if(nr >= 0 && nr < N && nc >= 0 && nc < M){
                    if(!visited2[nr][nc]){
                        visited2[nr][nc] = true;
                        q_copy.push(make_pair(nr, nc));
                    }
                }
            }
        }
        q = q_copy;
        while(!q_copy.empty()){
            q_copy.pop();
        }
        cnt++;
    }
    pair<int,int> ans = make_pair(15,15);
    while(!res.empty()){
        int ans_r = res.front().first;
        int ans_c = res.front().second;
        res.pop();
        if(ans.second > ans_c){
            ans = make_pair(ans_r, ans_c);
        }
    }
    while(!q.empty()){
        q.pop();
    }
    memset(visited2, false, sizeof(visited2));
    return ans;
}


void simulation(){
    int cnt = 0;
    for(int round = 0; round <= N; round++){
        // 1. 각 궁수의 입장에서 타겟을 선택 -> BFS
        pair<int,int> target[3];
        // 1-1. 1,2,3번째 궁수의 타겟 정하기
        target[0] = bfs(N, arrow[1]);
        target[1] = bfs(N, arrow[2]);
        target[2] = bfs(N, arrow[3]);
        // 2. 궁수는 적을 죽이고, count
        for(int i = 0; i < 3; i++){
            int _r = target[i].first;
            int _c = target[i].second;
            if(map[_r][_c] == 1){
                map[_r][_c] = 0;
                cnt++;
            }
        }
        // 3. 적의 전진
        for(int i = N-1; i >= 1; i--){
            for(int j = 0; j < M; j++){
                map[i][j] = map[i-1][j];
            }
        }
        for(int i = 0; i < M; i++){
            map[0][i] = 0;
        }
    }
    
    if(cnt > _max){
        _max = cnt;
    }
}








bool visited[15]; // 브루트 포스를 위한 visited
void dp(int cnt){
    if(cnt == 4){
        simulation();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                map[i][j] = map_copy[i][j];
            }
        }
    }else{
        for(int i = arrow[cnt-1]; i < M; i++){
            if(!visited[i]){
                visited[i] = true;
                arrow[cnt] = i;
                dp(cnt + 1);
                visited[i] = false;
            }
        }
    }
}




int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    // input
    cin >> N >> M >> D;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            map_copy[i][j] = map[i][j];
        }
    }
    // 1. 궁수 배치하는 case 만들기! -> 백트래킹!
    // 2. 각각의 케이스에서 시뮬레이션 구현! -> 거리 계산하는 과정은 BFS로!
    dp(1);
    
    cout << _max << "\n";
    
    return 0;
}
