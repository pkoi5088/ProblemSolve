#include <iostream>
#define MAX 1000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/11053
*/

void solve() {
    int arr[MAX],dp[MAX]={0,};
    int N,ret=0;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    for(int i=0;i<N;++i){
        //기본 자기자신
        dp[i]=1;

        //arr[i]를 선택할 경우
        for(int j=0;j<i;++j){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ret=max(ret,dp[i]);
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