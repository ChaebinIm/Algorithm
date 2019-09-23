//
//  main.cpp
//  MeetingRoom
//
//  Created by 임채빈 on 23/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int,int>> v; // {{시작, 끝}, 시간} 형태로 입력받음.

bool cmp(const pair<int,int> &p1, const pair<int,int> &p2){
    if(p1.second < p2.second){
        return true;
    }else if(p1.second == p2.second){
        return p1.first < p2.first;
    }else{
        return false;
    }
}



int main() {
    cout << "start" << endl;
    // 입력받기.
    cin >> N;
    for(int i = 0; i < N; i++){
        int _start, _end;
        cin >> _start >> _end;
        // {{시작, 끝}, 시간} 형태로 입력받음.
        v.push_back({_start, _end});
    }
    // 시간을 1우선순위, 끝나는 시각을 2우선순위로 sorting한다. 이때, NlogN의 시간복잡도를 가져야 되기 때문에 퀵 정렬을 이용하겠다.
    sort(v.begin(), v.end(), cmp);
    // 선택한다.
    int cnt = 0;
    int earliest = 0;
    for(int i = 0; i < v.size(); i++){
        int _start, _end;
        _start = v[i].first;
        _end = v[i].second;
        if(_start >= earliest){
            cnt++;
            earliest = _end;
        }
    }
    cout << cnt << "\n";
    return 0;
}
