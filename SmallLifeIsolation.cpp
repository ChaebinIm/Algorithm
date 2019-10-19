//
//  main.cpp
//  SmallLifeIsolation
//
//  Created by 임채빈 on 19/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int T, N, M, K, res;
class insects;
vector<insects> v, v_next;
int map[100][100];
int dirset[100][100];
int maxset[100][100];
class insects{
public:
    int r;
    int c;
    int size;
    int dir; // 1 : 상, 2 : 하, 3 : 좌, 4 : 우
    
    insects(int _r, int _c, int _size, int _dir){
        r = _r;
        c = _c;
        size = _size;
        dir = _dir;
    }
};

void move(int idx){
    int r = v[idx].r;
    int c = v[idx].c;
    int dir = v[idx].dir;
    int size = v[idx].size;
    if(dir == 1){
        int nr = r - 1;
        int nc = c;
        if(nr >= 1 && nr < N-1 && nc >= 1 && nc < N-1){
            if(map[nr][nc] == 0){
                map[nr][nc] = size;
                maxset[nr][nc] = size;
                dirset[nr][nc] = dir;
            }else{
                if(size > maxset[nr][nc]){
                    maxset[nr][nc] = size;
                    dirset[nr][nc] = dir;
                }
                map[nr][nc] += size;
            }
        }else if(nr >= 0 && nr < N && nc >= 0 && nc < N){
            map[nr][nc] = size/2;
            dirset[nr][nc] = 2;
        }
    }else if(dir == 2){
        int nr = r + 1;
        int nc = c;
        if(nr >= 1 && nr < N-1 && nc >= 1 && nc < N-1){
            if(map[nr][nc] == 0){
                map[nr][nc] = size;
                maxset[nr][nc] = size;
                dirset[nr][nc] = dir;
            }else{
                if(size > maxset[nr][nc]){
                    maxset[nr][nc] = size;
                    dirset[nr][nc] = dir;
                }
                map[nr][nc] += size;
            }
        }else if(nr >= 0 && nr < N && nc >= 0 && nc < N){
            map[nr][nc] = size/2;
            dirset[nr][nc] = 1;
        }
    }else if(dir == 3){
        int nr = r;
        int nc = c-1;
        if(nr >= 1 && nr < N-1 && nc >= 1 && nc < N-1){
            if(map[nr][nc] == 0){
                map[nr][nc] = size;
                maxset[nr][nc] = size;
                dirset[nr][nc] = dir;
            }else{
                if(size > maxset[nr][nc]){
                    maxset[nr][nc] = size;
                    dirset[nr][nc] = dir;
                }
                map[nr][nc] += size;
            }
        }else if(nr >= 0 && nr < N && nc >= 0 && nc < N){
            map[nr][nc] = size/2;
            dirset[nr][nc] = 4;
        }
    }else if(dir == 4){
        int nr = r;
        int nc = c+1;
        if(nr >= 1 && nr < N-1 && nc >= 1 && nc < N-1){
            if(map[nr][nc] == 0){
                map[nr][nc] = size;
                maxset[nr][nc] = size;
                dirset[nr][nc] = dir;
            }else{
                if(size > maxset[nr][nc]){
                    maxset[nr][nc] = size;
                    dirset[nr][nc] = dir;
                }
                map[nr][nc] += size;
            }
        }else if(nr >= 0 && nr < N && nc >= 0 && nc < N){
            map[nr][nc] = size/2;
            dirset[nr][nc] = 3;
        }
    }
    
}




int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> T;
    for(int test = 1; test <= T; test++){
        res = 0;
        // input
        cin >> N >> M >> K;
        for(int i = 0; i < K; i++){
            int i1, i2, i3, i4;
            cin >> i1 >> i2 >> i3 >> i4;
            v.push_back(insects(i1, i2, i3, i4));
        }
        
        for(int i = 0; i < M; i++){
            for(int j = 0; j < v.size(); j++){
                move(j);
            }
            v.clear();
            for(int a = 0; a < N; a++){
                for(int b = 0; b < N; b++){
                    if(map[a][b] != 0){
                        v.push_back(insects(a, b, map[a][b], dirset[a][b]));
                    }
                }
            }
            if(i != M-1){
                memset(map, 0, sizeof(map));
                memset(dirset, 0, sizeof(dirset));
                memset(maxset, 0, sizeof(maxset));
            }
        }
        int res = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j] != 0){
                    res += map[i][j];
                }
            }
        }
        cout << "#" << test << " " << res << "\n";
        memset(map, 0, sizeof(map));
        memset(dirset, 0, sizeof(dirset));
        memset(maxset, 0, sizeof(maxset));
    }
    return 0;
}
