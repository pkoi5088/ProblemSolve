#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1005
*/

int getDP(int n,vector<int>& dp,vector<int>& arr,vector<vector<int>>& graph){
    int& ret=dp[n];
    if(ret!=-1) return ret;

    ret=0;
    for(int i=0;i<graph[n].size();++i){
        ret=max(ret,getDP(graph[n][i],dp,arr,graph));
    }
    ret+=arr[n];
    return ret;
}

void solve() {
    int N,K;
    cin>>N>>K;
    vector<int> dp(N,-1),arr(N);
    vector<vector<int>> graph(N,vector<int>());
    for(int i=0;i<N;++i)
        cin>>arr[i];
    while(K--){
        int a,b;
        cin>>a>>b;
        graph[b-1].push_back(a-1);
    }
    int target;
    cin>>target;
    cout<<getDP(target-1,dp,arr,graph)<<endl;
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