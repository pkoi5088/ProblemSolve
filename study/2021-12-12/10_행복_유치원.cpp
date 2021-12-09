#include <iostream>
#include <algorithm>
#define MAX 300000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/13164
*/

void solve() {
    int N,K,arr[MAX],ret=0;
	cin>>N>>K;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	for(int i=1;i<N;++i){
		arr[i-1]=arr[i]-arr[i-1];
		ret+=arr[i-1];
	}
	sort(arr,arr+N-1,greater<>());
	for(int i=0;i<K-1;++i)
		ret-=arr[i];
	cout<<ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}