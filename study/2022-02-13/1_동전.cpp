#include <iostream>
#include <cstring>
#define MAX 20
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/9084
*/
int N,M;
int arr[MAX],dp[MAX][10001];

int getDP(int idx,int money){
	if(money==0) return 1;
	int& ret=dp[idx][money];
	if(ret!=-1) return ret;

	ret=0;
	for(int cnt=0;cnt*arr[idx]<=money;++cnt){
		ret+=getDP(idx-1,money-cnt*arr[idx]);
	}
	return ret;
}

void solve() {
	memset(dp,-1,sizeof(dp));
	cin>>N;
	for(int i=0;i<N;++i)
		cin>>arr[i];
	cin>>M;
	for(int i=0;i<=M;++i){
		dp[0][i]=(i%arr[0]==0);
	}
	cout<<getDP(N-1,M)<<endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
	    solve();
	return 0;
}