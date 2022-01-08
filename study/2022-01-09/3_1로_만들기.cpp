#include <iostream>
#include <cstring>
#define MAX 1000001
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1463
*/

int dp[MAX];

int getDP(int X){
    if(dp[X]!=-1) return dp[X];

    dp[X]=MAX;
    if(X%3==0) dp[X]=min(dp[X],getDP(X/3)+1);
    if(X%2==0) dp[X]=min(dp[X],getDP(X/2)+1);
    return dp[X]=min(dp[X],getDP(X-1)+1);
}

void solve() {
    memset(dp,-1,sizeof(dp));
    dp[1]=0;
    int X;
    cin>>X;
    cout<<getDP(X);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}