//
//  main.cpp
//  Tomato_3D
//
//  Created by 임채빈 on 26/08/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
// 3차원 근접한 위치에 접근하기 위한 배열들
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
// BFS 다음 턴에 갈 곳을 체크
bool willvisit[100][100][100];
// 3차원의 값을 가진 (토마토)Box -> class로 만들었음.
class Box{
public:
    int x;
    int y;
    int z;
    Box(int _x, int _y, int _z){
        x = _x;
        y = _y;
        z = _z;
    }
};

// 각 토마토의 위치를 나타내는 3차원 배열 map
int map[100][100][100];
// x, y, z 방향 주어진 값 M, N, H
int M, N, H;
// BFS를 위한 q와 q 초기화를 위한 q_copy
queue<Box> q, q_copy;


// check함수 : 전체에 0이 있는지 체크하는 과정. 즉, 출력값이 -1인지 아닌지 판별하는 과정.
bool check(){
    int res = true;
    for(int k = 0; k < H && res; k++){
        for(int i = 0; i < N && res; i++){
            for(int j = 0; j < M && res; j++){
                if(map[i][j][k] == 0){
                    res = false;
                    break;
                }
            }
        }
    }
    return res;
}

// 가장 중요한 함수. 3차원 배열을 살펴보며 BFS 1회씩 진행.
void bfs(){
    //Box 타입의 queue를 이용하여 BFS 진행
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();
        if(map[x][y][z] == 0)
            map[x][y][z] = 1;
        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx >= 0 && nx <= N-1 && ny >= 0 && ny <= M-1 && nz >= 0 && nz <= H-1 && !willvisit[nx][ny][nz] && map[nx][ny][nz] == 0){
                willvisit[nx][ny][nz] = true;
                q_copy.push(Box(nx,ny,nz));
            }
        }
    }
    
    q = q_copy;
    int _size = q_copy.size();
    for(int i = 0; i < _size; i++)
        q_copy.pop();
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << "start" << endl;
    //input -> 중요함. 3중 for문을 사용할때 순서가 3차 -> 2차 -> 1차로 진행.
    //쉽게말해 z축을 먼저 고려하고, y축(세로) - x축(가로)을 고려.
    cin >> M >> N >> H;
    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> map[i][j][k];
                if(map[i][j][k] == 1){
                    q.push(Box(i,j,k));
                    willvisit[i][j][k] = true;
                }
            }
        }
    }
    // BFS 진행하며 토마토가 익는 과정 진행.
    int cnt = 0;
    while(!q.empty()){
        bfs();
        cnt++;
    }
    
    // 전체 토마토가 다익었는지 확인
    bool result = check();
    
    //토마토가 다익었다면 cnt-1출력, 다익지 않았다면 -1 출력
    if(result){
        cout << cnt-1 << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
