#include <iostream>
#define MAX 100000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1912
*/

void solve() {
    int arr[MAX],dp[MAX];
    int n,ret=-1001;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    for(int i=0;i<n;++i){
        dp[i]=arr[i];
        if(i!=0)
            dp[i]=max(dp[i],dp[i-1]+arr[i]);
        ret=max(ret,dp[i]);
    }
    cout<<ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}