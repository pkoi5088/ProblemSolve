#include <iostream>
#define MAX 1500001
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/15486
*/

pair<int,int> arr[MAX];
int dp[MAX]={0,};

void solve() {
    int N,ret=-1;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i].first>>arr[i].second;
    }

    for(int i=0;i<N;++i){
        int next=i+arr[i].first,pay=arr[i].second;

        //상담을 안한다
        if(i+1<=N)
            dp[i+1]=max(dp[i],dp[i+1]);
        if(next>N) continue;
        dp[next]=max(dp[next],dp[i]+pay);
    }
    
    for(int i=0;i<=N;++i){
        ret=max(ret,dp[i]);
        cout<<dp[i]<<' ';
    }
    cout<<endl;
    cout<<ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}