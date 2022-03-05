#include <iostream>
#include <cstring>
#define MAX_N  10
#define MAX_M 2001
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2758
*/

long long dp[MAX_N][MAX_M];
int N,M;

//n번째의 숫자제한이 m일때
long long getDP(int n,int m){
    long long& ret=dp[n][m];
    if(ret!=-1) return ret;

    //기저사례
    if((1<<n)>m) return ret=0;
    else if(n==0) return ret=m;

    ret=getDP(n,m-1)+getDP(n-1,m/2);
    return ret;
}

void solve() {
    memset(dp,-1,sizeof(dp));
    cin>>N>>M;
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