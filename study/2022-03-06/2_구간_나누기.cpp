#include <iostream>
#include <cstring>
#define MAX 100
#define INF -1000000000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2228
*/

int dp[MAX][MAX/2+1],arr[MAX];
int N,M;

int getDP(int n,int m){
    if(n<0||m<=0) return INF;
    int& ret=dp[n][m];
    if(ret!=INF) return ret;

    //기저사례
    if(m==1){
        ret=max(arr[n],getDP(n-1,m)+arr[n]);
        return ret;
    }else if(n+1<m/2+m%2){
        return ret=INF+1;
    }

    ret=max(getDP(n-2,m-1)+arr[n],getDP(n-1,m)+arr[n]);
    for(int i=0;i<=n-2;++i){
        ret=max(ret,getDP(i,m-1)+arr[n]);
    }
    return ret;
}

void solve() {
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<=M;++j){
            dp[i][j]=INF;
        }
    }
    
    int ret=INF;
    for(int i=0;i<N;++i){
        ret=max(ret,getDP(i,M));
    }
    cout<<ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}