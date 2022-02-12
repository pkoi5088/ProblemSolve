#include <string>
#include <vector>
#define MAX 500

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/43105
*/

int dp[MAX][MAX]={0,};

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0]=triangle[0][0];
    for(int i=1;i<triangle.size();++i){
        for(int j=0;j<=i;++j){
            if(j==0){
                dp[i][j]=max(dp[i][j],dp[i-1][j]+triangle[i][j]);
            }else if(j==i){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+triangle[i][j]);
            }else{
                dp[i][j]=max(dp[i][j],dp[i-1][j]+triangle[i][j]);
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+triangle[i][j]);
            }
            answer=max(answer,dp[i][j]);
        }
    }
    return answer;
}