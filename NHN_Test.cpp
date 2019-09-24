//
//  main.cpp
//  NHN_test
//
//  Created by 임채빈 on 24/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int N, rotation;
string map[100][100];
string map_copy[100][100];

void move(int line){
    //어떻게 시계방향, 반시계방향을 구할 것이냐?
    if((rotation > 0 && line%2 == 0) || (rotation < 0 && line%2 == 1)){
        //시계방향 변환
        for(int i = line+1; i < N-line; i++){
            map_copy[line][i] = map[line][i-1];
            map_copy[i][N-1-line] = map[i-1][N-1-line];
            map_copy[N-1-line][N-1-i] = map[N-1-line][N-i];
            map_copy[N-1-i][line] = map[N-i][line];
        }
    }else{
        //반시계방향 변환
        for(int i = line+1; i < N-line; i++){
            map_copy[i][line] = map[i-1][line];
            map_copy[N-1-line][i] = map[N-1-line][i-1];
            map_copy[N-1-i][N-1-line] = map[N-i][N-1-line];
            map_copy[line][N-1-i] = map[line][N-i];
        }
    }
    //map_copy를 map에 입힌다.
    for(int i = line+1; i < N-line; i++){
        map[line][i] = map_copy[line][i];
        map[i][N-1-line] = map_copy[i][N-1-line];
        map[N-1-line][N-1-i] = map_copy[N-1-line][N-1-i];
        map[N-1-i][line] = map_copy[N-1-i][line];
    }
}



int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> N >> rotation;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            map_copy[i][j] = map[i][j];
        }
    }
    int flag = 0;
    for(int j = 0; j < N/2; j++){
        if(N % 2 == 1){
            flag = 8*(N/2-j);
        }else{
            flag = 8*(N/2-j)-4;
        }
        for(int i = 0; i < abs(rotation)%flag; i++){
            move(j);
        }
    }
    
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j != N-1)
                cout << map[i][j] << " ";
            else
                cout << map[i][j] << "\n";
        }
    }
    return 0;
}
