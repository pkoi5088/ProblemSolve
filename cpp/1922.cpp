#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	Node(int& c, int& f, int& t) {
		cost = c; from = f; to = t;
	}
	int cost, from, to;
};

bool operator<(Node& a, Node& b) {
	return a.cost > b.cost;
}

void ch(vector<int>& p, int a, int b) {
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == a)
			p[i] = b;
	}
}

int function(vector<Node>& v, vector<int>& p) {
	int r = 0;
	while (!v.empty()) {
		int c = v.back().cost;
		int f = v.back().from;
		int t = v.back().to;
		v.pop_back();

		if (p[f] == p[t])
			continue;

		r += c;
		if (p[f] > p[t])
			ch(p, p[f], p[t]);
		else
			ch(p, p[t], p[f]);
	}
	return r;
}

int main() {
	int N, M;
	vector<Node> v;
	vector<int> p;
	cin >> N >> M;
	for (int i = 0; i < N + 1; i++) {
		p.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(Node(c, a, b));
	}

	sort(v.begin(), v.end());

	cout << function(v, p);
	return 0;
}