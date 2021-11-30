#include <iostream>
#include <algorithm>
#define MAX 1000
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/11508
*/

void solve() {
    int N,arr[MAX];
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i];
    sort(arr,arr+N);
    for(int l=0;l<2;++l){
        for(int i=1;i<N;++i){
            arr[i]+=arr[i-1];
        }
    }
    cout<<arr[N-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}