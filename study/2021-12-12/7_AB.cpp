#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/16953
*/

void solve() {
    int A,B,ret=0;
    cin>>A>>B;
    while(B!=0){
        if(A==B){
            cout<<ret+1;
            return;
        }
        if(B%2==0)
            B/=2;
        else if(B%10==1)
            B/=10;
        else
            break;
        ret+=1;
    }
    cout<<-1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}