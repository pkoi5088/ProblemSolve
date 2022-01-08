#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12939#
*/

bool cmp(string s1,string s2){
    if(s1[0]=='-'&&s2[0]=='-'){
        s1.erase(0,1);
        s2.erase(0,1);
        return stoi(s1)>stoi(s2);
    }else if(s1[0]!='-'&&s2[0]!='-'){
        return stoi(s1)<stoi(s2);
    }
    return s1[0]=='-';
}

string solution(string s) {
    string answer = "",tmp;
    vector<string> v;
    for(int i=0;i<s.size();++i){
        if(s[i]==' '){
            v.push_back(tmp);
            tmp.clear();
        }else{
            tmp.push_back(s[i]);
        }
    }
    v.push_back(tmp);
    sort(v.begin(),v.end(),cmp);
    answer=v.front()+" "+v.back();
    return answer;
}