#include <iostream>
#include <string>
#define MAX 10
#define endl '\n'

using namespace std;

void solve() {
	string tmp;
	cin >> tmp;
	int cnt = 0;
	for (char& c : tmp) {
		cout << c;
		cnt += 1;
		if (cnt == 10) {
			cout << endl;
			cnt = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
