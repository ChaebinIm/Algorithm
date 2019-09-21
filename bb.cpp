
bool top_domain(string s){
    return s == ".com" || s == ".net" || s == ".org";
}



int solution(vector<string> emails){
    int answer = 0;
    for(int i = 0; i < emails.size(); i++){
        string s = emails[i];
        // 탑도메인 체크
        bool flag1 = top_domain(s.substr(s.length()-4,4));
        if(!flag1){
            break;
        }
        // 이름 체크
        int check_point = 0;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '@'){
                check_point = j; //체크포인트 구하고,
                break;
            }
        }
        bool flag2 = true;
        for(int j = 0; j < check_point; j++){
            if(!((s[j] >= 97 && s[j] <= 122) || s[j] == '.')){
                flag2 = false;
                break;
            }
        }
        if(!flag2){
            break;
        }
        // 도메인이름 체크
        bool flag3 = true;
        for(int j = check_point; j < s.length()-4; j++){
            if(!(s[j] >= 97 && s[j] <= 122)){
                flag3 = false;
                break;
            }
        }
        if(!flag3){
            break;
        }
        answer++;
    }
    return answer;
}
