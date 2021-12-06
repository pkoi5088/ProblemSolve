#include <iostream>
#include <algorithm>
#define MAX 10
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/11047
*/

void solve() {
    int N,K,ret=0,arr[MAX];
    cin>>N>>K;
    for(int i=0;i<N;++i)
        cin>>arr[i];
    sort(arr,arr+N,greater<>());
    int idx=0;
    while(K!=0){
        if(K>=arr[idx]){
            int t=K/arr[idx];
            K-=t*arr[idx];
            ret+=t;
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