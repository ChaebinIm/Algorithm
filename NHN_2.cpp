//
//  main.cpp
//  NHN_2
//
//  Created by 임채빈 on 29/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int N;
int arr[101]; // 빈도수 측정을 위한 배열
vector<int> v1, v2, v_cand;
int main(int argc, const char * argv[]) {
    cout << "Start" << endl;
    cin >> N;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        if(s == "enqueue"){
            int num;
            cin >> num;
            arr[num]++;
            v1.push_back(num);
        }else if(s == "dequeue"){
            if(v1.empty()){
                cout << -1 << "\n";
            }else{
                // 뺄 수를 결정 -> 제일 빈도가 높으면서, 제일 먼저 enqueue된 수.
                    //1. 높은 빈도 찾기.
                int _max = 0;
                for(int i = 1; i < 101; i++){
                    if(arr[i] > _max){
                        _max = arr[i];
                    }
                }
                    //2. 높은 빈도를 가진 candidate 찾기.
                for(int i = 1; i < 101; i++){
                    if(arr[i] == _max){
                        v_cand.push_back(i);
                    }
                }
                    //3. candidate 중에서 enqueue 빨리된애 찾기.
                int _idx = -1;
                for(int i = 0; i < v1.size(); i++){
                    for(int j = 0; j < v_cand.size(); j++){
                        if(v1[i] == v_cand[j]){
                            _idx = v_cand[j];
                            break;
                        }
                    }
                    if(_idx != -1){
                        break;
                    }
                }
                arr[_idx]--;
                // 뺄 수를 결정했으니, 빼자.
                bool flag = true;
                for(int i = 0; i < v1.size(); i++){
                    if(v1[i] == _idx && flag){
                        flag = false;
                        continue;
                    }else{
                        v2.push_back(v1[i]);
                    }
                }
                v1.clear();
                for(int i = 0; i < v2.size(); i++){
                    v1.push_back(v2[i]);
                }
                v2.clear();
                v_cand.clear();
                if(cnt == N-1){
                    cout << _idx;
                }else{
                    cout << _idx << " ";
                }
            }
        }
        cnt++;
    }
    return 0;
}
