#include <iostream>
#define MAX 1001
#define MOD 10007
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/11727
*/

int dp[MAX];

void solve() {
    dp[0]=dp[1]=1;
    int N;
    cin>>N;
    for(int i=2;i<=N;++i){
        dp[i]=(dp[i-1]+dp[i-2]*2)%MOD;
    }
    cout<<dp[N];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}