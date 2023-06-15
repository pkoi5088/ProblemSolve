#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	string s;
	int i;
	cin >> s >> i;
	cout << s[i - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
