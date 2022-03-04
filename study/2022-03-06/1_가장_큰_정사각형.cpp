#include <iostream>
#include <string>
#include <cstring>
#define MAX 1000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1915
*/

int dp[MAX][MAX],arr[MAX][MAX];

int min(int a,int b){
    if(a==-1) return b;
    else if(b==-1) return a;
    return a<b?a:b;
}

void solve() {
    int n,m,ret=0;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        string tmp;
        cin>>tmp;
        for(int j=0;j<m;++j){
            dp[i][j]=arr[i][j]=tmp[j]-'0';
        }
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(arr[i][j]==0) continue;
            int tmp=-1;
            //위
            if(i-1>=0){
                tmp=min(tmp,dp[i-1][j]);
            }else{
                tmp=0;
            }
            //왼
            if(j-1>=0){
                tmp=min(tmp,dp[i][j-1]);
            }else{
                tmp=0;
            }
            //왼위
            if(i-1>=0&&j-1>=0){
                tmp=min(tmp,dp[i-1][j-1]);
            }else{
                tmp=0;
            }

            if(tmp!=-1)
                dp[i][j]=tmp+1;
            ret=max(ret,dp[i][j]*dp[i][j]);
        }
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