#include <iostream>
#include <cstring>
#define MAX 5000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1695
*/

int min(int a,int b){
    if(a==-1) return b;
    else if(b==-1) return a;
    return a<b?a:b;
}

int dp[MAX][MAX],arr[MAX];
int N;

int getDP(int start,int end){
    if(start>end) return 0;
    int& ret=dp[start][end];
    if(ret!=-1) return ret;

    //기저사례
    if(start==end) return ret=0;

    if(arr[start]==arr[end]) ret=getDP(start+1,end-1);
    ret=min(ret,getDP(start+1,end)+1);
    ret=min(ret,getDP(start,end-1)+1);
    return ret;
}

void solve() {
    memset(dp,-1,sizeof(dp));
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i];
    cout<<getDP(0,N-1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}