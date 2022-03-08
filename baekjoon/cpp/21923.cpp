#include <iostream>
#include <cstring>
#define INF -100000000
#define MAX 1000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/21923
*/

//0: start->?, 1: ?->end
int dp[MAX][MAX][2],arr[MAX][MAX];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int N,M;

int getDP(int n,int m,int flag){
    int& ret=dp[n][m][flag];
    if(ret!=INF) return ret;

    if(flag==0){
        for(int i=1;i<3;++i){
            int nx=n+dx[i],ny=m+dy[i];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            ret=max(ret,getDP(nx,ny,flag)+arr[n][m]);
        }
    }else{
        for(int i=1;i<4;i+=2){
            int nx=n+dx[i],ny=m+dy[i];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            ret=max(ret,getDP(nx,ny,flag)+arr[n][m]);
        }
    }
    return ret;
}

void solve() {
    cin>>N>>M;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>arr[i][j];
            dp[i][j][0]=dp[i][j][1]=INF;
        }
    }
    dp[N-1][0][0]=arr[N-1][0];
    dp[N-1][M-1][1]=arr[N-1][M-1];
    
    int ret=INF;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            ret=max(ret,getDP(i,j,0)+getDP(i,j,1));
        }
    }
    cout<<ret<<endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}