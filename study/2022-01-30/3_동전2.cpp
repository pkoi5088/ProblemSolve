#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX_N 100
#define MAX_K 10001
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2294
*/

vector<int> arr;
int dp[MAX_K];

void solve() {
	for(int i=0;i<=MAX_K;++i)
		dp[i]=100000000;
    int n,k;
	cin>>n>>k;
	for(int i=0;i<n;++i){
		int tmp;
		cin>>tmp;
        if(tmp<=k){
			arr.push_back(tmp);
			dp[arr.back()]=1;
		}
	}
	sort(arr.begin(),arr.end());
	dp[0]=0;
	for(int i=0;i<arr.size();++i){
		for(int m=arr[i];m<=k;++m){
			if(dp[m]==-1&&dp[m-arr[i]]==-1) continue;
			if(dp[m]==-1)
				dp[m]=dp[m-arr[i]]+1;
			else
				dp[m]=min(dp[m],dp[m-arr[i]]+1);
		}
	}
	cout<<(dp[k]==100000000?-1:dp[k]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}