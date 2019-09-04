//
//  main.cpp
//  Seeking
//
//  Created by 임채빈 on 29/08/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
queue<int> q, q_copy;
int N, K; // N은 출발지, K는 도착지
int cnt = 0;  //몇번 이동했는지 카운팅하는 
int res = 99999999;  //결과값
bool visited[200002];
void bfs(){
    while(!q.empty()){
        int val = q.front();
        q.pop();
        if(val == K){ //출발지 == 도착지인 경우 고려.
            res = cnt;
            while(!q.empty())
                q.pop();
            while(!q_copy.empty())
                q_copy.pop();
            break;
        }
        if(val > K){ //출발지 > 도착지인 경우 고려 및 연산량 줄이기 위함.
            if(!visited[val-1]){
                visited[val-1] = true;
                q_copy.push(val-1);
            }
        }else{ // +1의 경우
            if(val+1 == K){ //+1이 목적지일 경우
                res = cnt+1;
                while(!q.empty())
                    q.pop();
                while(!q_copy.empty())
                    q_copy.pop();
                break;
            }else if(val+1 <= 100000 && !visited[val+1]){ // 목적지가 아니고, 범위를 벗어나지 않고, 아직까지 방문하지 않은 경우
                visited[val+1] = true;
                q_copy.push(val+1);
            }
            //*2의 경우
            if(val*2 == K){ //*2가 목적지일 경우
                res = cnt+1;
                while(!q.empty())
                    q.pop();
                while(!q_copy.empty())
                    q_copy.pop();
                break;
            }else if(val*2 <= 100000 && !visited[val*2]){ //목적지가 아니고, 범위를 벗어나지 않고, 아직까지 방문하지 않은 경우.
                visited[val*2] = true;
                q_copy.push(val*2);
            }
            //-1의 경우  
            if(val-1 >= 0 && !visited[val-1]){ // -1이 목적지일 수는 없다. 애초에 val <= K임이 전제되어 있기 때문.
                visited[val-1] = true;
                q_copy.push(val-1);
            }
        }
        
    }
    //다음 방문할 위치를 할당시킴.
    q = q_copy;
    //q_copy초기화
    while(!q_copy.empty())
        q_copy.pop();
    
}



int main(int argc, const char * argv[]) {
    //입츨력속도높이기
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << "start" << endl;
    //입력받고
    cin >> N >> K;
    //BFS
    q.push(N);
    while(!q.empty()){
        bfs();
        cnt++;
    }
    cout << res << endl;
    
    return 0;
}
