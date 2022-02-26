#include <string>
#include <vector>
#include <map>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/67258
*/

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string,int> table;
    for(string g:gems)
        table[g]=0;
    
    int start=0,end=0;
    int now=1,goal=table.size();
    table[gems[start]]=1;
    while(start<=end){
        if(now==goal){
            if(answer.empty()||end-start<answer[1]-answer[0]){
                if(answer.empty()) answer.resize(2);
                answer[0]=start+1;
                answer[1]=end+1;
            }
            
            if(table[gems[start]]<=1)
                now-=1;
            table[gems[start]]-=1;
            start+=1;
        }else{
            end+=1;
            if(end==gems.size()) break;
            if(table[gems[end]]==0) now+=1;
            table[gems[end]]+=1;
        }
    }
    return answer;
}