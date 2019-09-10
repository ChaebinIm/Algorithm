//
//  main.cpp
//  N&M_1
//
//  Created by 임채빈 on 10/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[9];
bool visited[9];
void dp(int cnt){
    
    //결과 조건을 만족할 때 : 즉, size가 M인 벡터가 만들어졌을 때.
    if (cnt == M){
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    // 백트래킹
    for(int i = 1; i <= N; i++){
        // 1부터 N까지 배열에 넣겠지만, 이미 넣은 것은 넣지 않겠다. -> 백트래킹
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            dp(cnt+1);
            visited[i] = false;
        }
    }
}




int main(int argc, const char * argv[]) {
    cin >> N >> M;
    dp(0);
    return 0;
}
