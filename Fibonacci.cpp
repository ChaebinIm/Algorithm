//
//  main.cpp
//  Fibonacci
//
//  Created by 임채빈 on 05/11/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
using namespace std;
int N;

long long fibo(int n){ // 재귀를 이용한 피보나치 함수 구하기.
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }
    return fibo(n-1) + fibo(n-2);
}
int main(int argc, const char * argv[]) {
    cout << "start" << "\n";
    cin >> N; // 임의의 수 N을 입력받으면
    cout << fibo(N) << "\n"; // 피보나치 함수 값을 계산하여 출력
    return 0;
}
