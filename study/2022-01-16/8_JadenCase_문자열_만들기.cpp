#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12951
*/

string solution(string s) {
    string answer = "",tmp;
    s+=" ";
    for(int i=0;i<s.size();++i){
        if(s[i]==' '){
            answer+=(tmp+" ");
            tmp.clear();
        }else{
            if(tmp.empty()){
                if('a'<=s[i]&&s[i]<='z'){
                    s[i]-='a'-'A';
                }
                tmp.push_back(s[i]);
            }else{
                if('A'<=s[i]&&s[i]<='Z'){
                    s[i]-='A'-'a';
                }
                tmp.push_back(s[i]);
            }
        }
    }
    answer.pop_back();
    return answer;
}