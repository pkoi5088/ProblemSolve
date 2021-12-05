#include <iostream>
#include <algorithm>
#define MAX 10000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/20300
*/

void solve() {
    long long arr[MAX],ret=-1;
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i];
    sort(arr,arr+N);
    if(N%2){
        ret=arr[N-1];
        N-=1;
    }
    for(int i=0;i<N/2;++i){
        ret=max(ret,arr[N-i-1]+arr[i]);
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