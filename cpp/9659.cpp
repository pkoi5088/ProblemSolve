#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	long long N;
	cin >> N;
	switch (N % 4) {
	case 0:
		cout << "CY";
		break;

	case 1:
		cout << "SK";
		break;

	case 2:
		if (N == 2)
			cout << "SK";
		else
			cout << "CY";
		break;

	case 3:
		cout << "SK";
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
