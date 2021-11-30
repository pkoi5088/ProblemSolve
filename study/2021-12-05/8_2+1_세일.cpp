#include <iostream>
#include <algorithm>
#define MAX 100000
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/11508
*/

void solve() {
    int N,arr[MAX],ret=0;
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i];
    sort(arr,arr+N,greater<>());
    for(int i=0;i<N;++i){
        if(i%3!=2)
            ret+=arr[i];
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