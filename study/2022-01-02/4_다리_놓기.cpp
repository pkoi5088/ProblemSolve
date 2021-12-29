#include <iostream>
#include <cstring>
#define MAX 31
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1010
*/

int combination[MAX][MAX];

int getCombination(int n,int m){
    if(combination[n][m]!=-1) return combination[n][m];

    if(n==m||m==0) return combination[n][m]=1;
    else if(m==1||m==n-1) return combination[n][m]=n;

    return combination[n][m]=getCombination(n-1,m)+getCombination(n-1,m-1);
}

void solve() {
    int N,M;
    cin>>N>>M;
    cout<<getCombination(M,N)<<endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
    memset(combination,-1,sizeof(combination));
    int T;
    cin>>T;
    while(T--)
	    solve();
	return 0;
}