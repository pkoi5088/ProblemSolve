#include <iostream>
#include <algorithm>
#define MAX 100000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1758
*/

void solve() {
    int N,arr[MAX];
    long long ret=0;
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i];
    sort(arr,arr+N,greater<>());
    for(int i=0;i<N;++i){
        ret+=(long long)(arr[i]-i<0?0:arr[i]-i);
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