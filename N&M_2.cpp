//
//  main.cpp
//  N&M_2
//
//  Created by 임채빈 on 11/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
using namespace std;
int N, M, arr[9];
bool visited[9];
void dp(int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }else{
        /*
         입력으로 4 2 를 했을때,
         1 - 2
           - 3
           - 4
         2 - 3
           - 4
         3 - 4
         이렇게 되야하니까, 전역 int 배열 arr에 정수 a를 추가하고 나서 한 차원 더 깊게 들어가면, a보다 큰 값부터 봐야함.
         그렇지 않으면
         1 - 2
           - 3
           - 4
         2 - 1
           - 3
           - 4
         3 - 1
           - 2
           - 4
         4 - 1
           - 2
           - 3
         이 된다.
         따라서, for문의 i의 초기 값은, 이전에 들어갔던 수보다 1만큼 큰 수가 되어야 한다.
         그래서 int i = arr[cnt-1]+1 로 지정한 것이다.
         여기서 한 가지 중요한 점이, 전역으로 arr을 선언했을 때, 그 배열의 모든 값이 0으로 초기화되기 때문에 이와 같은 과정이 가능.
         그렇지 않다면, 0으로 초기화해주는 과정이 필요하다.
         */
        for(int i = arr[cnt-1]+1; i <= N; i++){
            if(!visited[i]){
                visited[i] = true;
                arr[cnt] = i;
                dp(cnt+1);
                visited[i] = false;
            }
        }
    }

    
}


int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> N >> M;
    dp(0);
    return 0;
}
