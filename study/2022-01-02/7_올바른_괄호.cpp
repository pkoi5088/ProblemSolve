#include <string>
#include <iostream>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12909
*/

bool solution(string s)
{
    string tmp;
    for(int i=0;i<s.size();++i){
        if(s[i]=='('){
            tmp.push_back(s[i]);
        }else{
            if(tmp.empty())
                return false;
            else
                tmp.pop_back();
        }
    }
    return tmp.empty();
}