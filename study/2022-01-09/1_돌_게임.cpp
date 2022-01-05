#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/9655
*/

void solve() {
	int N;
	cin >> N;
	if (N % 4 == 1 || N % 4 == 3)
		cout << "SK";
	else
		cout << "CY";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}