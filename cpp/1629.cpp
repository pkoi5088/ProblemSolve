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

long long int c;

long long int f(long long int a, long long int b) {
	if (b == 0)return 1;
	long long int t1 = f(a, b / 2) % c;
	return b % 2 == 0 ? (t1 * t1) % c : (a * ((t1 * t1) % c) % c);
}

void solve() {
	long long int a, b;
	cin >> a >> b >> c;
	cout << f(a, b) % c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
