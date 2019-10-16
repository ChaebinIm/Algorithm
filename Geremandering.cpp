//
//  main.cpp
//  Geremandering
//
//  Created by 임채빈 on 15/10/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int N;
int score[11];
vector<int> relation[11];
bool visited[11];
int _min = 99999999;
bool success = false;
int arr[10];
bool visited_home[11], visited_away[11];
vector<int> home, away;


// 두 팀의 score 차이를 계산하는 함수.
int operate(){
    int sum_home = 0, sum_away = 0;
    for(int i = 0; i < home.size(); i++){
        sum_home += score[home[i]];
    }
    for(int i = 0; i < away.size(); i++){
        sum_away += score[away[i]];
    }
    return abs(sum_home - sum_away);
}

bool home_check(int n){
    int res = true;
    for(int i = 0; i < relation[n].size(); i++){
        int next = relation[n][i];
        if(!visited_home[next]){
            visited_home[next] = true;
            home_check(next);
        }
    }
    for(int i = 1; i <= N; i++){
        if(!visited_home[i]){
            res = false;
            break;
        }
    }
    return  res;
}


bool away_check(int n){
    int res = true;
    for(int i = 0; i < relation[n].size(); i++){
        int next = relation[n][i];
        if(!visited_away[next]){
            visited_away[next] = true;
            away_check(next);
        }
    }
    for(int i = 1; i <= N; i++){
        if(!visited_away[i]){
            res = false;
            break;
        }
    }
    return  res;
}



void dp(int cnt, int limit){
    if(cnt == limit){
        // home, away 팀 가르기
        int check_home = 0;
        int check_away = 0;
        for(int i = 1; i <= N; i++){
            if(visited[i]){
                home.push_back(i);
                visited_away[i] = true;
                check_home = i;
            }else{
                away.push_back(i);
                visited_home[i] = true;
                check_away = i;
            }
        }
        // home, away 모두 팀이 될 수 있는지 check
        visited_home[check_home] = true;
        visited_away[check_away] = true;
        bool isPossible = home_check(check_home) && away_check(check_away);
        
        // 팀이 될 수 있다면, 연산.
        if(isPossible){
            int res = operate();
            if(res < _min){
                _min = res;
            }
            success = true;
        }
        
        // 초기화
        memset(visited_home, false, sizeof(visited_home));
        memset(visited_away, false, sizeof(visited_away));
        home.clear();
        away.clear();
    }else{
        for(int i = arr[cnt-1]+1; i <= N; i++){
            if(!visited[i]){
                visited[i] = true;
                arr[cnt] = i;
                dp(cnt+1, limit);
                visited[i] = false;
            }
            
        }
    }
    
    
}



int main(){
    cout << "start" << endl;
    // input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int input;
            cin >> input;
            int chk = true;
            for(int k = 0; k < relation[i].size(); k++){
                if(relation[i][k] == input){
                    chk = false;
                    break;
                }
            }
            if(chk){
                relation[i].push_back(input);
            }
            chk = true;
            for(int k = 0; k < relation[input].size(); k++){
                if(relation[input][k] == i){
                    chk = false;
                    break;
                }
            }
            if(chk){
                relation[input].push_back(i);
            }
        }
    }
    
    for(int i = 2; i <= N/2+1; i++){
        dp(1,i);
    }
    
    if(success){
        cout << _min << "\n";
    }else{
        cout << -1 << "\n";
    }
    
}
