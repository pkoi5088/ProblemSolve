#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/92343
*/

vector<vector<int>> child;
int answer=0,N;

void dfs(int idx,int wolf,int sheep,int flag,vector<int>& info){
    if(info[idx]) wolf+=1;
    else sheep+=1;
    
    if(wolf>=sheep) return;
    
    answer=max(answer,sheep);
    
    for(int i=0;i<child[idx].size();++i){
        int next=child[idx][i];
        flag|=(1<<next);
    }
    
    for(int i=0;i<N;++i){
        if(flag&(1<<i)){
            flag&=~(1<<i);
            dfs(i,wolf,sheep,flag,info);
            flag|=(1<<i);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    N=info.size();
    child.resize(N);
    for(int i=0;i<edges.size();++i){
        child[edges[i][0]].push_back(edges[i][1]);
    }
    dfs(0,0,0,0,info);
    
    return answer;
}