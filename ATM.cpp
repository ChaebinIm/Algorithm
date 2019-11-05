//
//  main.cpp
//  ATM
//
//  Created by 임채빈 on 06/11/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> men;

int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    // input
    cin >> N;
    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        men.push_back(input);
    }
    
    // SJF(Shortest Job First)를 하기 위해 sorting한다.(오름차순)
    sort(men.begin(), men.end());
    
    // 대기시간을 포함한 Total Around Time 구하기!
    long long sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            sum += men[j];
        }
    }
    
    cout << sum << "\n";
    return 0;
}
