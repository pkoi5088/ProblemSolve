#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2056
*/

int dp[MAX],arr[MAX];
vector<int> pre[MAX];
int N;

int getDP(int n){
    int& ret=dp[n];
    if(ret!=-1) return ret;

    //기저사례
    if(pre[n].empty())
        return ret=arr[n];

    for(int i=0;i<pre[n].size();++i){
        ret=max(ret,getDP(pre[n][i])+arr[n]);
    }
    return ret;
}

void solve() {
    memset(dp,-1,sizeof(dp));
    cin>>N;
    for(int i=0;i<N;++i){
        int tmp;
        cin>>arr[i]>>tmp;
        while(tmp--){
            int p;
            cin>>p;
            pre[i].push_back(p-1);
        }
    }

    int ret=-1;
    for(int i=0;i<N;++i){
        ret=max(ret,getDP(i));
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