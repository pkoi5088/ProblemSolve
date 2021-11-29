#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2217
*/

void solve() {
    vector<int> v;
    int N,ret=0;
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;++i)
        cin>>v[i];
    sort(v.begin(),v.end(),greater<>());
    for(int i=0;i<N;++i){
        ret=max(ret,v[i]*(i+1));
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