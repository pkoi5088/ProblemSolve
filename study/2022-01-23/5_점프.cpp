#include <iostream>
#define MAX 100
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1890
*/

void solve() {
    long long arr[MAX][MAX],dp[MAX][MAX]={0,};
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>arr[i][j];
        }
    }
    
    dp[0][0]=1;
    for(int x=0;x<N;++x){
        for(int y=0;y<N;++y){
            if(x==N-1&&y==N-1) continue;
            if(dp[x][y]){
                int nx=x+arr[x][y],ny=y+arr[x][y];
                if(nx<N)
                    dp[nx][y]+=dp[x][y];
                if(ny<N)
                    dp[x][ny]+=dp[x][y];
            }
        }
    }
    cout<<dp[N-1][N-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}