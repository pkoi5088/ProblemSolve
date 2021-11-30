#include <iostream>
#include <algorithm>
#define MAX 100000
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/20115
*/

void solve() {
    int N;
    double arr[MAX];
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i];
    sort(arr,arr+N);
    for(int i=0;i<N-1;++i){
        arr[N-1]+=arr[i]/2;
    }
    cout<<arr[N-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	solve();
	return 0;
}