//
//  main.cpp
//  CoinZero
//
//  Created by 임채빈 on 06/11/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
using namespace std;
int N, K;
int coin[10];

int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    // input
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> coin[i];
    }
    int cnt = 0;
    int coin_val = K;
    for(int i = N-1; i >= 0; i--){
        int val = coin[i];
        while(coin_val >= val){
            cnt++;
            coin_val -= val;
        }
        if(coin_val == 0){
            break;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}
