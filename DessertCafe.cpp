//
//  main.cpp
//  DessertCafe
//
//  Created by 임채빈 on 19/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int map[20][20];
bool visited_dessert[101];
int dr[4] = {1, 1, -1, -1};
int dc[4] = {-1, 1, 1, -1};
int T, N;
int res;
int start_r, start_c;

void dfs(int r, int c, int cnt, int dir){
    if(cnt > 3 && r == start_r && c == start_c){
        if(res < cnt){
            res = cnt;
        }
        return;
    }
    int _dir = dir;
    while(_dir <= dir+1 && _dir < 4){
        int nr = r + dr[_dir];
        int nc = c + dc[_dir];
        if(nr >= 0 && nr < N && nc >= 0 && nc < N){
            if(!visited_dessert[map[nr][nc]]){
                visited_dessert[map[nr][nc]] = true;
                dfs(nr, nc, cnt+1, _dir);
                visited_dessert[map[nr][nc]] = false;
            }
        }

        if(nr == start_r && nc == start_c){
            dfs(nr, nc, cnt, _dir);
        }
        
        _dir++;
    }
    
    
}



int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> T;
    for(int test = 1; test <= T; test++){
        res = 0;
        
        // 입력받기
        cin >> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> map[i][j];
            }
        }
        
        // 모든 케이스에서 시도하기. (i, j)에서 시작한다.
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                start_r = i;
                start_c = j;
                visited_dessert[map[i][j]] = true;
                dfs(i, j, 1, 0);
                visited_dessert[map[i][j]] = false;
            }
        }
        
        if(res == 0){
            cout << "#" << " " << test << " " << -1 << "\n";
        }else{
            cout << "#" << " " << test << " " << res << "\n";
        }
    }
    
    
    
    
    
    
    return 0;
}
