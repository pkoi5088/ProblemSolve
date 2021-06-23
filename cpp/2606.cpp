#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
	vector<int> link;

	void connect(int n) {
		link.push_back(n);
	}
};

int main() {
	int N, cnt = -1;
	cin >> N;
	Node* board = new Node[N];
	bool* check = new bool[N];
	for (int i = 0; i < N; i++)
		check[i] = false;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		board[a - 1].connect(b - 1);
		board[b - 1].connect(a - 1);
	}

	queue<int> q;
	q.push(0);
	check[0] = true;
	while (q.empty() == false) {
		int c = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < board[c].link.size(); i++) {
			int next = board[c].link.at(i);
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
	cout << cnt;
	return 0;
}