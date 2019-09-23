#include <iostream>
using namespace std;
int n;
int arr[1000005];


int main(){
    cin >> n;
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i <= 1000004; i++){
        arr[i] = (arr[i-1] + arr[i-2])%15746;
    }
    cout <<  arr[n] << endl;
    
    
    
    return 0;
}
