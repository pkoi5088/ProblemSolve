#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12942
*/

vector<vector<int>> dp;

int getDP(int s,int e,vector<vector<int>>& matrix_sizes){
    int& ret=dp[s][e];
    if(ret!=-1) return ret;
    
    if(s==e) return ret=0;
    if(s+1==e){
        return ret=matrix_sizes[s][0]*matrix_sizes[s][1]*matrix_sizes[e][1];
    }
    
    for(int i=s;i<e;++i){
        if(ret==-1){
            ret=getDP(s,i,matrix_sizes)+getDP(i+1,e,matrix_sizes)+matrix_sizes[s][0]*matrix_sizes[i][1]*matrix_sizes[e][1];
        }else{
            ret=min(ret,getDP(s,i,matrix_sizes)+getDP(i+1,e,matrix_sizes)+matrix_sizes[s][0]*matrix_sizes[i][1]*matrix_sizes[e][1]);
        }
    }
    return ret;
}

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0,N=matrix_sizes.size();
    dp.resize(N,vector<int>(N,-1));
    answer=getDP(0,N-1,matrix_sizes);
    return answer;
}