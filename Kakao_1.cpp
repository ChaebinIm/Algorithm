//
//  main.cpp
//  Kakao_1
//
//  Created by 임채빈 on 07/09/2019.
//  Copyright © 2019 임채빈. All rights reserved.
// 목적 : 묶음으로 문자 압축할 수 있을 때 가장 작은 길이를 출력하는 것.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int solution(string s) {
    int answer = 1000;
    // 배열 인덱스 초과도 고려해 주어야함.
    for(int i = 1; i <= s.length()/2+1; i++){ // i는 비교 묶음의 크기
        int candidate = 0;
        int flag = 1; //나중에 자릿수도 고려해 주어야함.
        string check = "-1";
        for(int j = 0; j < s.length(); j += i){ //j는 현재 비교하는 문자열의 시작지점.
            if(i + j < 10000){
                string check_candidate = s.substr(j,i);
                if(check_candidate == check){
                    flag++;
                }
                if(check == "-1"){
                    check = check_candidate;
                }else if(check != check_candidate){
                    if(flag == 1){
                        candidate += i;
                    }else if(flag < 10){
                        candidate = candidate + i + 1;
                    }else if(flag >= 10 && flag < 100){
                        candidate = candidate + i + 2;
                    }else if(flag >= 100 && flag < 1000){
                        candidate = candidate + i + 3;
                    }else if(flag == 1000){
                        candidate = candidate + i + 4;
                    }
                    check = check_candidate;
                    flag = 1;
                }
            }
        }
        if(flag == 1){
            candidate += check.length();
        }else if(flag < 10){
            candidate = candidate + i + 1;
        }else if(flag >= 10 && flag < 100){
            candidate = candidate + i + 2;
        }else if(flag >= 100 && flag < 1000){
            candidate = candidate + i + 3;
        }else if(flag == 1000){
            candidate = candidate + i + 4;
        }
        if(answer > candidate){
            answer = candidate;
        }
    }
    return answer;
}



int main(int argc, const char * argv[]) {
    cout<< "start" << endl;
    string s;
    cin >> s;
    
    cout << solution(s) << endl;
    return 0;
}
