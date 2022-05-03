#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2753
*/

void solve() {
    int N;
    cin>>N;
    cout<<(N%400==0||(N%4==0&&N%100!=0));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}