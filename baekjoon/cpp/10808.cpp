#include <iostream>
#include <string>
#define MAX 10
#define endl '\n'

using namespace std;

void solve() {
	int cnt[26] = { 0, };
	string tmp;
	cin >> tmp;
	for (int i = 0; i < tmp.size(); ++i)
		cnt[tmp[i] - 'a']++;
	for (int i = 0; i < 26; ++i)
		cout << cnt[i] << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
