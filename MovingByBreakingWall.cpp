//
//  main.cpp
//  MovingWithBreakingWall
//
//  Created by 임채빈 on 05/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001]; //입력값을 받는 2차원 배열
int dr[4] = {0,0,-1,1}; //상하좌우탐색을 위함.
int dc[4] = {-1,1,0,0};
int cache[1001][1001][2]; //캐싱하는 함수. (행, 열, 벽뚫었는지)
int M, N;
queue<pair<pair<int,int>,int>> q; //BFS를 위한 큐

/*
 cache 사용한 이유 및 효과
 1. 연산량을 줄일 수 있다. 브루트포스 방법이 아닌, 딱 필요한 연산만 가능하다.
 2. BFS 함수를 반복할 필요가 없다. -> 내가 평소 하던 q_copy가 필요없다.
 3. visited를 사용할 필요가 없다.
 4. cache 함수 자체 안에 몇초가 지난 후 그곳을 방문했는지 기록된다.
 이는 상당히 효율적, 효과적이라고 볼 수 있다.
 
 또한, bfs함수의 리턴타입을 int로 하여 그 값을 이용하여 바로 결과값 출력이 가능하다.
 */

int bfs(){
    cache[1][1][0] = 1;
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int broken = q.front().second;
        q.pop();
        if(r == M && c == N){
            return cache[r][c][broken];
        }
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 1 && nr <= M && nc >= 1 && nc <= N){
                //방문하려는 곳이 벽이 있고, 지금까지 뚫은 적이 없을 경우.
                if(map[nr][nc] == 1 && broken == 0){
                    cache[nr][nc][1] = cache[r][c][0]+1;
                    q.push(make_pair(make_pair(nr,nc),1));
                }
                //방문하려는 곳이 벽이 없고, 지금까지 방문하지 않은 곳인 경우
                if(map[nr][nc] == 0 && cache[nr][nc][broken] == 0){
                    cache[nr][nc][broken] = cache[r][c][broken]+1;
                    q.push(make_pair(make_pair(nr,nc),broken));
                }
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> M >> N;
    for (int i = 1; i <= M; i++){
        string temp;
        cin >> temp;
        for (int j = 1; j <= N; j++)
            map[i][j] = temp[j-1] - '0';
    }
    q.push(make_pair(make_pair(1,1),0));
    cout << bfs() << endl;
    
    
    
    return 0;
}
