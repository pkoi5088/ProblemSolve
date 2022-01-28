#include <iostream>
#include <cstring>
#define MAX 101
#define MOD 1000000000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/10844
*/

int dp[MAX][10];

int getDP(int length,int number){
    if(number<0||number>=10) return 0;
    if(dp[length][number]!=-1) return dp[length][number];

    dp[length][number]=(getDP(length-1,number-1)+getDP(length-1,number+1))%MOD;
    return dp[length][number];
}

void solve() {
    memset(dp,-1,sizeof(dp));
    int N,ret=0;
    cin>>N;
    dp[1][0]=0;
    for(int i=1;i<10;++i){
        dp[1][i]=1;
    }
    for(int i=0;i<10;++i){
        ret+=getDP(N,i);
        ret%=MOD;
    }
    cout<<ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}