#include <iostream>
#include <cstring>
#define MAX 50001
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/17626
*/

int dp[MAX];

int getDP(int N){
    if(dp[N]!=-1) return dp[N];

    dp[N]=MAX;
    for(int i=1;i*i<=N;++i){
        dp[N]=min(dp[N],getDP(N-i*i)+1);
    }
    return dp[N];
}

void solve() {
    int N;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    cin>>N;
    cout<<getDP(N);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}