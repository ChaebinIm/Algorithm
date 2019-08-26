//
//  main.cpp
//  MazeSearch
//
//  Created by 임채빈 on 22/08/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int map[100][100];
bool willvisit[100][100];
int M,N;
int dr[4] = {0,0,-1,1};
int dc[4] = {-1,1,0,0};
int res = 0;
queue<pair<int,int>> q, q_copy;

void bfs(){
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        map[r][c] = 2;
        // 도착했다면,
        if(r == M-1 && c == N-1){
            while(!q.empty())
                q.pop();
            while(!q_copy.empty())
                q_copy.pop();
            break;
        }
        // 도착하지 않았다면,
        else{
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr <= M-1 && nc >= 0 && nc <= N-1 && map[nr][nc] == 1 &&
                    !willvisit[nr][nc]){
                    q_copy.push(make_pair(nr,nc));
                    willvisit[nr][nc] = true;
                }
            }
        }
    }
    q = q_copy;
    while(!q_copy.empty()){
        q_copy.pop();
    }
}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << "start" << endl;
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    q.push(make_pair(0,0));
    willvisit[0][0] = true;
    while(!q.empty()){
        bfs();
        res++;
    }
    cout << res  << endl;
    
    return 0;
}
