//
//  main.cpp
//  Hanoi
//
//  Created by 임채빈 on 05/11/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int N;
vector<pair<int,int>> res;

// N이 3이라고 가정해 보자. 이 때에는 3을 제외한 1,2를 구역 2로 옮기고, 3을 구역 3으로 옮긴 후, 나머지를 구역 3으로 옮겨야한다.
void hanoi(int n, int from, int to, int sub){
    if(n == 1){
        res.push_back({from, to}); // n == 1 일때란 쉽게 말해 1번째 구역에는 제일 큰 수 1개만 남아있는 경우를 말한다.
    }else{ // N이 3이라고 생각하면,
        hanoi(n-1, from, sub, to); // 처음에 1,2 를 2구역으로 옮기는 과정
        res.push_back({from, to}); // 3을 3으로 옮기는 과정
        hanoi(n-1, sub, to, from); // 2구역에 있는 1,2를 3으로 옮기는 과정
    } // 이렇게 문제를 작은 문제로 분할하는 과정을 이용하기 때문에 이 알고리즘은 "분할정복" 이라고 불린다.
}

int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> N;
    hanoi(N, 1, 3, 2);
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++){
        cout << res[i].first << " " << res[i].second << "\n";
    }
    return 0;
}
