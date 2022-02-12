#include <iostream>
#include <cstring>
#define MAX 201
#define MOD 1000000000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2225
*/

int dp[MAX][MAX];
int N,K;

int getDP(int n,int k){
    int& ret=dp[n][k];
    if(ret!=-1) return ret;

    ret=0;
    for(int i=0;i<=n;++i){
        ret+=getDP(n-i,k-1);
        ret%=MOD;
    }
    return ret%MOD;
}

void solve() {
    memset(dp,-1,sizeof(dp));
    cin>>N>>K;
    for(int i=0;i<=N;++i){
        dp[i][0]=0;
        dp[i][1]=1;
    }
    cout<<getDP(N,K);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}