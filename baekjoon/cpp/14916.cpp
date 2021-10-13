#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#define endl '\n'

using namespace std;

void solve() {
	int coin2 = 0, coin5 = 0;
	int N;
	cin >> N;
	coin5 = N / 5;
	switch (N % 5) {
	case 0:
	case 2:
	case 4:
		coin2 = (N % 5) / 2;
		break;
	case 1:
	case 3:
		coin5 -= 1;
		if (coin5 < 0) coin2 = -1;
		else coin2 = ((N % 5) + 5) / 2;
		break;
	}
	cout << (coin2 == -1 ? -1 : coin2 + coin5);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
