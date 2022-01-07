#include <iostream>
#include <vector>
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12913
*/

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int dp[4],tmpdp[4];
    for(int i=0;i<4;++i)
        dp[i]=land[0][i];
    for(int i=1;i<land.size();++i){
        for(int j=0;j<4;++j){
            int tmp=0;
            for(int k=0;k<4;++k){
                if(j==k) continue;
                tmp=max(tmp,dp[k]);
            }
            tmpdp[j]=tmp+land[i][j];
        }
        
        for(int j=0;j<4;++j){
            dp[j]=tmpdp[j];
        }
    }
    for(int i=0;i<4;++i)
        answer=max(answer,dp[i]);
    return answer;
}