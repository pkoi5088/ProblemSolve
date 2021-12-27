#include <iostream>
#define MAX 21
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/10870
*/

void solve() {
   int arr[MAX]={0,},N;
   arr[1]=1;
   cin>>N;
    for(int i=2;i<=N;++i){
        arr[i]=arr[i-2]+arr[i-1];
    }
    cout<<arr[N];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}