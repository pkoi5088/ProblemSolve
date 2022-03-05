#include <iostream>
#include <cstring>
#define MAX 500
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1520
*/

int dp[MAX][MAX],arr[MAX][MAX];
int N,M;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

int getDP(int n,int m){
    int& ret=dp[n][m];
    if(ret!=-1) return ret;
    
    ret=0;
    for(int i=0;i<4;++i){
        int nx=n+dx[i],ny=m+dy[i];
        if(nx<0||nx>=N||ny<0||ny>=M||arr[n][m]<=arr[nx][ny])
            continue;
        ret+=getDP(nx,ny);
    }
    return ret;
}

void solve() {
    memset(dp,-1,sizeof(dp));
    cin>>N>>M;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>arr[i][j];
        }
    }
    dp[N-1][M-1]=1;
    cout<<getDP(0,0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}