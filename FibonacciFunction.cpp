//
//  main.cpp
//  FibonacciFunction
//
//  Created by 임채빈 on 10/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> v;
void func(int num){
    /*
     p[0] = 1 0
     p[1] = 0 1
     p[2] = p[1] + p[0] = 1 1
     p[3] = p[2] + p[1] = 2p[1] + p[0] = 1 2
     p[4] = p[3] + p[2] = 3p[1] + 2p[0] = 2 3
     p[5] = p[4] + p[3] = 5p[1] + 3p[0] = 3 5
     p[6] = p[5] + p[4] = 8p[1] + 5p[0] = 5 8
     ...
     */
    if(num > v.size()-1){
        for(int i = v.size(); i <= num; i++){
            int val1 = v[i-1].first + v[i-2].first;
            int val2 = v[i-1].second + v[i-2].second;
            v.push_back(make_pair(val1,val2));
        }
    }else{
    }
}

int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    int testNum;
    cin >> testNum;
    v.push_back(make_pair(1,0));
    v.push_back(make_pair(0,1));
    for(int i = 1; i <= testNum; i++){
        int inp;
        cin >> inp;
        func(inp);
        cout << v[inp].first << " " << v[inp].second << endl;
    }
    
    return 0;
}
