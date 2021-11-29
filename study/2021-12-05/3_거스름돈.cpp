#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/14916
*/

void solve() {
    int n,coin2=0,coin5=0;
    cin>>n;
    while(n>=5){
        if(n%5==0){
            coin5=n/5;
            n=0;
            break;
        }
        n-=2;
        coin2+=1;
    }
    if(n==1||n==3) cout<<-1;
    else cout<<coin2+n/2+coin5;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}