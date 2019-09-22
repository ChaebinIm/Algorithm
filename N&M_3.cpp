//
//  main.cpp
//  N&M_3
//
//  Created by 임채빈 on 22/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
using namespace std;
int N, M;
int arr[7];
//bool visited[8];
void dp(int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        arr[cnt] = i;
        dp(cnt+1);
    }
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << "start" << endl;
    cin >> N >> M;
    dp(0);
    
    return 0;
}
