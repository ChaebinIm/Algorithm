//
//  main.cpp
//  MovingPipe
//
//  Created by 임채빈 on 15/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
using namespace std;
int N;
int map[17][17];
int dr[3] = {0, 1, 1};
int dc[3] = {1, 0, 1};
int res = 0;


void simulation(int r, int c, int method){ // r,c는 현재 위치 && method 0: 이전에 가로, 1 : 이전에 세로, 2 : 이전에 대각
    if(r == N && c == N){
        res++;
    }
    for(int i = 0; i < 3; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 1 && nr <= N && nc >= 1 && nc <= N && map[nr][nc] != 1){
            if(i == 2){ // 대각으로 이동하는 경우 -> 양옆 체크해야됨.
                if(map[nr][nc-1] == 0 && map[nr-1][nc] == 0){
                    simulation(nr, nc, 2);
                }else{
                    continue;
                }
            }else if(i == 0 && method != 1){ // 나머지 가로, 세로로 이동하는 경우 -> 45도만 회전할 수 있음을 고려!
                simulation(nr, nc, 0);
            }else if(i == 1 && method != 0){
                simulation(nr, nc, 1);
            }
        }
    }
}






int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }
    simulation(1, 2, 0);
    
    
    cout << res << "\n";
    
    return 0;
}
