#include <iostream>
#include <cstring>
#define MAX 300
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2579
*/

int stair[MAX],dp[MAX][2];

//flag: 전계단을 밟았는가
int getDP(int n,int flag){
    if(n<0) return 0;
    if(dp[n][flag]!=-1) return dp[n][flag];

    //밟았으면
    if(flag){
        dp[n][flag]=getDP(n-1,0)+stair[n];
    }

    //안밟았으면
    dp[n][flag]=max(dp[n][flag],max(getDP(n-2,0),getDP(n-2,1))+stair[n]);
    return dp[n][flag];
}

void solve() {
    memset(dp,-1,sizeof(dp));
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>stair[i];
    dp[0][0]=stair[0];
    dp[0][1]=0;
    cout<<max(getDP(N-1,0),getDP(N-1,1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}