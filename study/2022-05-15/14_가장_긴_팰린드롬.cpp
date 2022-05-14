#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> dp;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12904
*/

int getDP(int s,int e,string& str){
    if(dp[s][e]!=-1) return dp[s][e];
    
    //기저사례
    if(s==e) return dp[s][e]=1;
    else if(s+1==e) return dp[s][e]=(str[s]==str[e]);
    
    if(str[s]==str[e])
        return dp[s][e]=getDP(s+1,e-1,str);
    return dp[s][e]=0;
}

int solution(string s)
{
    int answer=0,N=s.size();
    dp.resize(N,vector<int>(N,-1));
    
    for(int i=0;i<N;++i){
        for(int j=i;j<N;++j){
            if(getDP(i,j,s)){
                answer=max(answer,j-i+1);
            }
        }
    }
    return answer;
}