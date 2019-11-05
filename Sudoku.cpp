//
//  main.cpp
//  Sudoku
//
//  Created by 임채빈 on 04/11/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int map[9][9];
// row[a][b] 는 a 행이 값 b(1~9사이)를 가지고 있는가?
// col[a][b] 는 b 열이 값 b(1~9사이)를 가지고 있는가?
// mat[a][b] 는 9 번쩨 3*3 크기 부분 매트릭스에서 값 b(1~9사이)를 가지고 있는가?
bool row[9][10], col[9][10], mat[9][10];

void output(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}


void dfs(int n){
    if(n == 81){ // 9 * 9 = 81이기 때문에 81개의 값 모두가 채워졌을 때(0이 아닐 때), 출력하고 끝.
        output();
        exit(0);
    }else{
        // r, c는 현재 값의 위치(행, 렬)
        int r = n/9;
        int c = n%9;
        if(map[r][c] == 0){
            for(int i = 1; i <= 9; i++){ // 빈칸이 0이라면, 1~9의 값중 어느 것이 들어갈 수 있는지 보겠다.
                if(!row[r][i] && !col[c][i] && !mat[3*(r/3)+c/3][i]){ // 해당 위치의 행, 렬, 3*3메트릭스 모든 조건에서 해당 값(i)을 가지고 있지 않을 때..
                    row[r][i] = true;
                    col[c][i] = true;
                    mat[3*(r/3) + c/3][i] = true;
                    map[r][c] = i;
                    dfs(n + 1);
                    map[r][c] = 0;
                    row[r][i] = false;
                    col[c][i] = false;
                    mat[3*(r/3) + c/3][i] = false;
                }
            }
        }else{
            // 0이 아니면 통과하고 다음 과정을 진행.
            dfs(n+1);
        }
    }
}





int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    // input
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> map[i][j];
            if(map[i][j] != 0){
                row[i][map[i][j]] = true;
                col[j][map[i][j]] = true;
                mat[3*(i/3)+(j/3)][map[i][j]] = true;
            }
        }
    }
    
    // 모든 경우의 수에 맞게 돌리기
    dfs(0);
    return 0;
}
