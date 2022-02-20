#include <iostream>
#include <cstring>
#define MAX 100
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/5557
*/

long long dp[MAX][21],arr[MAX];

//N인덱스에서 K일때 경우의 수
long long getDP(int N,int K){
    if(N<0||K<0||K>20) return 0;
    long long& ret=dp[N][K];
    if(ret!=-1) return ret;

    ret=getDP(N-1,K+arr[N])+getDP(N-1,K-arr[N]);
    return ret;
}

void solve() {
    memset(dp,-1,sizeof(dp));
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    dp[0][arr[0]]=1;
    cout<<getDP(N-2,arr[N-1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}