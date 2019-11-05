//
//  main.cpp
//  Padovan
//
//  Created by 임채빈 on 06/11/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
using namespace std;
int N;
int arr[101];
int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    // input과 dp 배열 만들기
    cin >> N;
    arr[0] = 0;
    arr[1] = arr[2] = arr[3] = 1;
    arr[4] = 2;
    // 파도반 수열은 아래 식의 규칙을 가진다.
    for(int i = 5; i <= 100; i++){
        arr[i] = arr[i-1] + arr[i-5];
    }
    int n;
    for(int test = 1; test <= N; test++){
        cin >> n;
        cout << arr[n] << "\n";
    }
    return 0;
}
