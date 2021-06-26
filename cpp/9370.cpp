#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 2000000000

using namespace std;

class Vertex {
public:
	int dist = INF;
	int index;
	vector<pair<int, int>> next;

	bool operator < (const Vertex& v) const{
		return dist < v.dist;
	}

	bool operator > (const Vertex& v) const{
		return dist > v.dist;
	}
};

int main() {
	//n교차로 m도로 t목적지후보
	//s출발지 gh필수코스
	int T;
	cin >> T;
	while (T--) {
		//입력
		int n, m, t, s, g, h;
		cin >> n >> m >> t >> s >> g >> h;
		vector<int> finish;

		Vertex* vertex = new Vertex[n + 1];

		for (int i = 1; i <= n; i++) {
			vertex[i].index = i;
		}
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			d *= 2;
			if ((a == g && b == h) || (a == h && b == g))
				d -= 1;
			vertex[a].next.push_back({ b,d });
			vertex[b].next.push_back({ a,d });
		}
		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			finish.push_back(x);
		}

		priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
		vertex[s].dist = 0;
		pq.push(vertex[s]);
		while (!pq.empty()) {
			Vertex now = pq.top();
			pq.pop();
			for (int k = 0; k < now.next.size(); k++) {
				int ni = now.next[k].first;
				int money = now.next[k].second;
				if (vertex[ni].dist > now.dist + money) {
					vertex[ni].dist = now.dist + money;
					pq.push(vertex[ni]);
				}
			}
		}
		sort(finish.begin(), finish.end());
		for (int j = 0; j < finish.size(); j++) {
			if (vertex[finish[j]].dist % 2 == 1)
				cout << finish[j] << ' ';
		}
		cout << endl;
		finish.clear();
		delete[] vertex;
	}
	return 0;
}