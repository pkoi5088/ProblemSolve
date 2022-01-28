#include <iostream>
#include <cstring>
#define MAX 10000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2156
*/

int N;
int arr[MAX],dp[MAX];

int getDP(int idx){
    if(dp[idx]!=-1) return dp[idx];

    dp[idx]=max(getDP(idx-2)+arr[idx],getDP(idx-3)+arr[idx-1]+arr[idx]);
    dp[idx]=max(dp[idx],getDP(idx-1));
    return dp[idx];
}

void solve() {
    memset(dp,-1,sizeof(dp));
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i];
    if(N==1){
        cout<<arr[0];
    }else if(N==2){
        cout<<arr[0]+arr[1];
    }else{
        dp[0]=arr[0];
        dp[1]=dp[0]+arr[1];
        cout<<getDP(N-1)<<endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}