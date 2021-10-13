#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;

int n, t, g;
bool visited[MAX];

void minus_front(int& n) {
	int digit = 1;
	while (digit <= n)
		digit *= 10;
	digit /= 10;
	n -= digit;
}

int BFS() {
	queue<pair<int, int>>q;
	q.push({ n,0 });
	visited[n] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt > t)
			break;

		if (cur == g)
			return cnt;

		int A = cur + 1;
		if (A < MAX && !visited[A]) {
			visited[A] = true;
			q.push({ A,cnt + 1 });
		}

		int tmp = cur * 2;
		if (tmp >= MAX)
			continue;

		int B = tmp;
		minus_front(B);
		if (B < MAX && !visited[B]) {
			visited[B] = true;
			q.push({ B,cnt + 1 });
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t >> g;

	int result = BFS();
	if (result == -1)
		cout << "ANG\n";
	else
		cout << result << "\n";
	return 0;
}