//
//  main.cpp
//  Rope
//
//  Created by 임채빈 on 06/11/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int N;
vector<int> v;



int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    // input
    cin >> N;
    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        v.push_back(input);
    }
    // 높은 값 순서대로 sorting하기. Greedy하게 풀기 위함.
    sort(v.begin(), v.end(), greater<>());
    
    // 현재 최고와 앞으로 최고가 될 가능성이 있는 경우를 모두 고려.
    int sum_best = v[0], sum_now = v[0];
    for(int i = 0; i < v.size(); i++){
        // 취하는 것
        sum_now = (i+1) * v[i];
        if(sum_now > sum_best){
            sum_best = sum_now;
        }
    }
    cout << sum_best << "\n";
    
    return 0;
}
