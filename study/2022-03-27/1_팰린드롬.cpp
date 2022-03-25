#include <iostream>
#include <cstring>
#define MAX 2000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/10942
*/

int dp[MAX][MAX],arr[MAX];
int N,M;

int getDP(int s,int e){
    int& ret=dp[s][e];
    if(ret!=-1) return ret;

    //기저사례
    if(s==e){
        return ret=1;
    }else if(s+1==e){
        return ret=(arr[s]==arr[e]);
    }

    ret=0;
    if(arr[s]==arr[e]){
        ret=getDP(s+1,e-1);
    }
    return ret;
}

void solve() {
    memset(dp,-1,sizeof(dp));
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i];
    cin>>M;
    while(M--){
        int a,b;
        cin>>a>>b;
        cout<<getDP(a-1,b-1)<<endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}