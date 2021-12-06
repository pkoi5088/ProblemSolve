#include <iostream>
#include <algorithm>
#define MAX 100000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1931
*/

bool cmp(const pair<int,int>& p1,const pair<int,int>& p2){
	if(p1.second==p2.second)
		return p1.first<p2.first;
	return p1.second<p2.second;
}

void solve() {
	pair<int,int> arr[MAX];
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr,arr+N,cmp);
	
	int idx=0,end=0,ret=0;
	while(idx<N){
		if(end<=arr[idx].first){
			ret+=1;
			end=arr[idx].second;
		}
		idx+=1;
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