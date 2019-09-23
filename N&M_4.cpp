#include <iostream>
using namespace std;
int arr[9];
int M, N;

void dp(int cnt){
    if(cnt == M+1){
        for(int i = 1; i <= M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }else{
        for(int i = arr[cnt-1]; i <= N; i++){
            arr[cnt] = i;
            dp(cnt + 1);
        }
        
    }
    
    
    
    
}


int main(){
    cin >> N >> M;
    arr[0] = 1;
    dp(1);
    return 0;
}
