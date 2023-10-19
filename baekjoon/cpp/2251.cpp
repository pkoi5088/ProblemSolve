#include <iostream>
#include <queue>
#include <set>
#define endl '\n'
#define MAX 201

using namespace std;

struct State {
	int A, B, C;
	State(int ia, int ib, int ic) {
		A = ia, B = ib, C = ic;
	}
};

bool check[MAX][MAX][MAX] = { false };

void solve() {
	int startA, startB, startC;
	cin >> startA >> startB >> startC;

	queue<State> q;
	q.push(State(0, 0, startC));
	check[0][0][startC] = true;
	while (!q.empty()) {
		int nowA = q.front().A, nowB = q.front().B, nowC = q.front().C;
		q.pop();

		int nextA, nextB, nextC, move;

		// A -> B
		move = min(nowA, startB - nowB);
		nextA = nowA - move, nextB = nowB + move, nextC = nowC;
		if (check[nextA][nextB][nextC] == false) {
			q.push(State(nextA, nextB, nextC));
			check[nextA][nextB][nextC] = true;
		}

		// A -> C
		move = min(nowA, startC - nowC);
		nextA = nowA - move, nextB = nowB, nextC = nowC + move;
		if (check[nextA][nextB][nextC] == false) {
			q.push(State(nextA, nextB, nextC));
			check[nextA][nextB][nextC] = true;
		}

		// B -> A
		move = min(nowB, startA - nowA);
		nextA = nowA + move, nextB = nowB - move, nextC = nowC;
		if (check[nextA][nextB][nextC] == false) {
			q.push(State(nextA, nextB, nextC));
			check[nextA][nextB][nextC] = true;
		}

		// B -> C
		move = min(nowB, startC - nowC);
		nextA = nowA, nextB = nowB - move, nextC = nowC + move;
		if (check[nextA][nextB][nextC] == false) {
			q.push(State(nextA, nextB, nextC));
			check[nextA][nextB][nextC] = true;
		}

		// C -> A
		move = min(nowC, startA - nowA);
		nextA = nowA + move, nextB = nowB, nextC = nowC - move;
		if (check[nextA][nextB][nextC] == false) {
			q.push(State(nextA, nextB, nextC));
			check[nextA][nextB][nextC] = true;
		}

		// C -> B
		move = min(nowC, startB - nowB);
		nextA = nowA, nextB = nowB + move, nextC = nowC - move;
		if (check[nextA][nextB][nextC] == false) {
			q.push(State(nextA, nextB, nextC));
			check[nextA][nextB][nextC] = true;
		}
	}

	set<int> setC;
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			if (check[0][i][j]) {
				setC.insert(j);
			}
		}
	}

	for (auto c : setC) {
		cout << c << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}