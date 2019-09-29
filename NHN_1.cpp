//
//  main.cpp
//  NHN_1
//
//  Created by 임채빈 on 29/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N;
map<string, int> m;
vector<string> v;

int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        if ( m.find(s) == m.end() ) { // 없을 시,
            m.insert(make_pair(s,1));
            v.push_back(s);
        } else { // 있을 시,
            m[s]++;
        }
    }
    // 찾아야된다.
    int _max = 0, _min = 1000;
    string _min_key = " ";
    for ( auto info : m){
        int val = info.second;
        if(val > _max){
            _max = val;
        }
        if(val < _min){
            _min = val;
            _min_key = info.second;
        }
    } // 출처 : https://hashcode.co.kr/questions/605/stdmap%EC%9D%84-auto%EB%A1%9C-%EC%A0%91%EA%B7%BC%ED%95%98%EB%8A%94-%EB%B0%A9%EB%B2%95
    if(_min == _max){
        cout << "Y" << "\n" << N << "\n" << m.size() << endl;
    }else if(_max - _min == 1){
        // 짝이 다른 녀석이 한놈인지 체크해야함.
        int cnt = 0;
        for ( auto info : m){
            int val = info.second;
            if(val == _min){
                cnt++;
            }
        }
        if(cnt == 1){
            // 짝이 다른 녀석이 한놈이라면,
            cout << "Y" << "\n" << N+1 <<"\n" <<  m.size() << endl;
        }else if(cnt > 1){
            cout << "N" << "\n" << N <<"\n" <<  m.size() << endl;
        }
    }else{
        cout << "N" << "\n" << N <<"\n" <<  m.size() << endl;
    }
    return 0;
}
