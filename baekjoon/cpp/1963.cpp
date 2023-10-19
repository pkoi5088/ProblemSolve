#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <queue>
#define endl '\n'
#define MAX 10000

using namespace std;

bool prime[MAX];

void createPrime() {
	memset(prime, true, sizeof(prime));

	for (int i = 2; i < MAX; ++i) {
		if (prime[i] == false) continue;

		for (int j = i * 2; j < MAX; j += i) {
			prime[j] = false;
		}
	}
}

void solve() {
	string start, end;
	cin >> start >> end;

	bool check[MAX] = { false };
	queue<pair<string, int>> q;
	q.push({ start,0 });
	while (!q.empty()) {
		string now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == end) {
			cout << cnt << endl;
			return;
		}

		string next;
		for (int l = 0; l < now.size(); ++l) {
			next = now;
			for (int i = 0; i < 10; ++i) {
				next[l] = '0' + i;
				if (check[stoi(next)] || prime[stoi(next)]==false) continue;
				if (stoi(next) < 1000) continue;
				q.push({ next,cnt + 1 });
				check[stoi(next)] = true;
			}
		}
	}
	cout << "Impossible" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	createPrime();
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}