#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/20053
*/

void solve() {
    int MIN=1000001,MAX=-1000001;
    int N;
    cin>>N;
    while(N--){
        int tmp;
        cin>>tmp;
        MIN=min(MIN,tmp);
        MAX=max(MAX,tmp);
    }
    cout<<MIN<<' '<<MAX<<endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
	    solve();
	return 0;
}