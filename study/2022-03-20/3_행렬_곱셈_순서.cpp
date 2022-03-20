#include <iostream>
#include <cstring>
#define MAX 500
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/11049
*/

int min(int a,int b){
    if(a==-1) return b;
    if(b==-1) return a;
    return a<b?a:b;
}

pair<int,int> arr[MAX];
int dp[MAX][MAX];
int N;

int getDP(int start,int end){
    int& ret=dp[start][end];
    if(ret!=-1) return ret;

    //기저사례
    if(start==end)
        return ret=0;
    else if(start+1==end)
        return ret=arr[start].first*arr[start].second*arr[end].second;

    for(int i=start;i<end;++i){
        ret=min(ret,getDP(start,i)+getDP(i+1,end)+arr[start].first*arr[end].second*arr[i].second);
    }
    return ret;
}

void solve() {
    memset(dp,-1,sizeof(dp));
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i].first>>arr[i].second;
    cout<<getDP(0,N-1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}