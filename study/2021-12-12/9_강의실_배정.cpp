#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 200000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/11000
*/

bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second<p2.second;
}

void solve() {
    priority_queue<int,vector<int>,greater<int>> pq;
    pair<int,int> arr[MAX];
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i].first>>arr[i].second;

    sort(arr,arr+N);
    for(int i=0;i<N;++i){
        if(!pq.empty()&&pq.top()<=arr[i].first)
            pq.pop();
        pq.push(arr[i].second);
    }
    cout<<pq.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}