#include <iostream>
#include <cstring>
#include <vector>
#define MAX 1000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/14567
*/

int dp[MAX];
vector<int> edge[MAX];

int getDP(int n){
    if(dp[n]!=-1) return dp[n];

    if(edge[n].empty()) return dp[n]=1;
    
    for(int i=0;i<edge[n].size();++i){
        dp[n]=max(dp[n],getDP(edge[n][i])+1);
    }
    return dp[n];
}

void solve() {
    memset(dp,-1,sizeof(dp));
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        edge[b-1].push_back(a-1);
    }
    for(int i=0;i<N;++i){
        cout<<getDP(i)<<' ';
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}