#include <iostream>
#define MAX 31
#define endl '\n'

using namespace std;

void solve() {
	int A[MAX],B[MAX];
	A[1]=B[2]=1;
	A[2]=B[1]=0;
	for(int i=3;i<MAX;++i){
		A[i]=A[i-1]+A[i-2];
		B[i]=B[i-1]+B[i-2];
	}

	int D,K;
	cin>>D>>K;
	for(int i=1;i<=K;++i){
		for(int j=i;j<=K;++j){
			if(A[D]*i+B[D]*j==K){
				cout<<i<<endl<<j;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}