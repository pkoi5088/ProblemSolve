#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/5597
*/

void solve() {
    bool arr[31]={false,};
    for(int i=0;i<28;++i){
        int tmp;
        cin>>tmp;
        arr[tmp]=true;
    }
    for(int i=1;i<31;++i){
        if(arr[i]==false) cout<<i<<endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}