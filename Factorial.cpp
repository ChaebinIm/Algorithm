//
//  main.cpp
//  Factorial
//
//  Created by 임채빈 on 05/11/2019.
//  Copyright © 2019 임채빈. All rights reserved.
//

#include <iostream>
using namespace std;
int N;

long long factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return factorial(n-1) * n;
}



int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    cin >> N;
    cout << factorial(N) << "\n";
    return 0;
}
