

#include <iostream>
#include <vector>
using namespace std;
int N, L;
int map[100][100];
int res = 0;

bool check(vector<int> v){
    // 오르막의 경우, 내리막의 경우가 있을 것이다.
    int now = v[0];
    int flag = 1;
    for(int i = 1; i < N; i++){
        if(v[i] == now){ // 같은 높이일 경우
            flag++;
        }else if(v[i] == now + 1){ // 오르막일 경우
            if(flag >= L){
                flag = 1;
                now = now + 1;
                continue;
            }else{
                return false;
            }
        }else if(v[i] == now - 1){ // 내리막일 경우
            if(i+L-1< N){
                flag = 0;
                for(int j = 0; j < L; j++){
                    if(v[i+j] == now - 1){
                        flag++;
                    }else{
                        return false;
                    }
                }
                if(flag == L){
                    now = now - 1;
                    i = i + L - 1;
                    flag = 0;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    
    return true;
}

void rWalk(){
    for(int i = 0; i < N; i++){
        // 1. 1줄씩 입력 받는다.
        vector<int> v;
        for(int j = 0; j < N; j++){
            v.push_back(map[i][j]);
        }
        // 2. 경사로를 지나갈 수 있는지 체크한다.
        if(check(v)){
            res++;
        }
    }
}

void cWalk(){
    for(int j = 0; j < N; j++){
        // 1. 1줄씩 입력 받는다.
        vector<int> v;
        for(int i = 0; i < N; i++){
            v.push_back(map[i][j]);
        }
        // 2. 경사로를 지나갈 수 있는지 체크한다.
        if(check(v)){
            res++;
        }
    }
}


int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    //1. 입력받기
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    //2. 세로 체크
    cWalk();
    //3. 가로 체크
    rWalk();
    
    //4. 결과값 출력.
    cout << res << "\n";
    return 0;
}
