#include <iostream>
#include <vector>
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12971
*/

int solution(vector<int> sticker)
{
    int answer=0,N=sticker.size();
    vector<int> dp(N,0);
    if(N==1) return sticker[0];
    
    //0번 인덱스를 골랐을 때
    dp[0]=dp[1]=sticker[0];
    for(int i=2;i<N-1;++i){
        dp[i]=max(dp[i-1],dp[i-2]+sticker[i]);
    }
    answer=dp[N-2];
    
    //0번 인덱스를 골랐을 때
    dp[0]=0;
    dp[1]=sticker[1];
    for(int i=2;i<N;++i){
        dp[i]=max(dp[i-1],dp[i-2]+sticker[i]);
    }
    answer=max(answer,dp[N-1]);
    return answer;
}