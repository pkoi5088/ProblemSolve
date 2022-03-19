#include <vector>
#include <cstring>
#define MAX 500
 
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/1832
*/
 
int MOD = 20170805;
 
int solution(int m, int n, vector<vector<int>> city_map) {
    int dp[MAX][MAX][2]={0,};
    int N=m,M=n;
    dp[0][0][0]=dp[0][0][1]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(city_map[i][j]==1) continue;
            if(city_map[i][j]==0){
                if(i!=0){
                    dp[i][j][0]+=dp[i-1][j][0];
                    dp[i][j][1]+=dp[i-1][j][0];
                }
                if(j!=0){
                    dp[i][j][0]+=dp[i][j-1][1];
                    dp[i][j][1]+=dp[i][j-1][1];
                }
                dp[i][j][0]%=MOD;
                dp[i][j][1]%=MOD;
            }
            else{
                if(i!=0)
                    dp[i][j][0]=dp[i-1][j][0]%MOD;
                if(j!=0)
                    dp[i][j][1]=dp[i][j-1][1]%MOD;
            }
        }
    }
    return ((dp[N-1][M-1][0]+dp[N-1][M-1][1])/2%MOD);
}