//
//  main.cpp
//  ToothedWheel
//
//  Created by 임채빈 on 14/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int wheel[4][8];
int N;
bool Isrotated[4];

// 왼쪽 톱니바퀴가 돌 수 있는지 체크. true면 돌 수 있음.
bool left_check(int num){
    bool flag = !(wheel[num][6] == wheel[num-1][2]);
    return flag;
}

// 오른쪽 톱니바퀴가 돌 수 있는지 체크.
bool right_check(int num){
    bool flag = !(wheel[num][2] == wheel[num+1][6]);
    return flag;
}

// 회전시키는 함수.
void rotate(int num, int method){
    Isrotated[num] = true;
    int wheel_temp[8];
    // 왼쪽 회전 여부 체크
    if(num != 0){
        if(left_check(num) && !Isrotated[num-1]){
            rotate(num-1, (-1)*method);
        }
    }
    // 오른쪽 회전 여부 체크
    if(num != 3){
        if(right_check(num) && !Isrotated[num+1]){
            rotate(num+1, (-1)*method);
        }
    }
    for(int i = 0; i < 8; i++){
        wheel_temp[i] = wheel[num][i];
    }
    if(method == 1){ // 시계방향
        // 회전
        int temp = wheel[num][7];
        for(int i = 1; i < 8; i++){
            wheel[num][i] = wheel_temp[i-1];
        }
        wheel[num][0] = temp;
    }else if(method == -1){ // 반시계방향
        // 회전
        int temp = wheel[num][0];
        for(int i = 0; i < 7; i++){
            wheel[num][i] = wheel_temp[i+1];
        }
        wheel[num][7] = temp;
    }
}



int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    // 톱니바퀴 내용 입력. N극은 0, S극은 1
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            int input;
            scanf("%1d", &input);
            wheel[i][j] = input;
        }
    }
    // 회전수 N 입력
    cin >> N;
    // 회전수 num과 회전방향 method입력. num-1번째 톱니바퀴를 method(1:시계, -1:반시계)로 돌리겠다.
    int num, method;
    for(int i = 0; i < N; i++){
        cin >> num >> method;
        num--;
        rotate(num, method);
        for(int j = 0; j < 4; j++){
            Isrotated[j] = false;
        }
    }
    
    int res = wheel[0][0] + 2*wheel[1][0] + 4*wheel[2][0] + 8*wheel[3][0];
    cout << res << "\n";
    
    return 0;
}
