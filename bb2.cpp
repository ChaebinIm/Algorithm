#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
queue<pair<int,int>> q;
int r, c;
bool stop = false;
bool used = false;
void check(char ch){
    if(ch == '#'){
        q.push(make_pair(r+1, c));
    }else if(ch == '>'){
        q.push(make_pair(r, c+1));
    }else if(ch == '<'){
        q.push(make_pair(r, c-1));
    }else if(ch == '*'){
        if(used){
            stop = true;
        }else{
            q.push(make_pair(r+1, c));
            used = true;
        }
    }else{
    }
}

int solution(vector<string> drum){
    int answer = 0;
    int _size = drum[0].length();
    // 각 test
    for(int test = 0; test < _size; test++){
        used = false;
        stop = false;
        // 처음 시작지점
        q.push(make_pair(0,test));
        while(!q.empty()){
            r = q.front().first;
            c = q.front().second;
            q.pop();
            check(drum[r][c]);
            if(stop)
                break;
        }
        if(r == _size)
            answer++;
        
        while(!q.empty())
            q.pop();
    }
    
    return answer;
}
