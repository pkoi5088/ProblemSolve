#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2839
*/

void solve() {
    int N,cnt3=0,cnt5=0;
    cin>>N;
    while(N>=3){
        if(N%5==0){
            cnt5+=N/5;
            N=0;
        }else{
            cnt3+=1;
            N-=3;
        }
    }
    if(N==0) cout<<cnt3+cnt5;
    else cout<<-1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}