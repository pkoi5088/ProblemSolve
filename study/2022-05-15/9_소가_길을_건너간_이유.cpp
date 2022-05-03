#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/14467
*/

void solve() {
    int arr[11];
    for(int i=0;i<11;++i){
        arr[i]=-1;
    }

    int n,ret=0;
    cin>>n;
    while(n--){
        int tmp,loc;
        cin>>tmp>>loc;
        if(arr[tmp]==-1)
            arr[tmp]=loc;
        else if(arr[tmp]!=loc){
            ret+=1;
            arr[tmp]=loc;
        }
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