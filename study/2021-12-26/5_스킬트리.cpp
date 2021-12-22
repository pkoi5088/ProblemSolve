#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/49993
*/

bool check(string s,int* arr){
    int next=1;
    for(int i=0;i<s.size();++i){
        if(arr[s[i]-'A']!=0){
            if(arr[s[i]-'A']!=next) return false;
            next+=1;
        }
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0,arr[26]={0,};
    for(int i=0;i<skill.size();++i){
        arr[skill[i]-'A']=i+1;
    }
    
    for(string& s:skill_trees){
        int next=1;
        if(check(s,arr))
            answer+=1;
    }
    return answer;
}