#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;

bool map[MAX] = { false };

int bfs(int& n,int& k) {
	queue<pair<int, int>> q;
	q.push({ n,0 });
	while (!q.empty()) {
		int location = q.front().first;
		int time = q.front().second;
		map[location] = true;
		q.pop();

		if (location == k)
			return time;

		if (location > 0 && !map[location - 1])
			q.push({ location - 1 ,time + 1 });
		if (location < MAX&&!map[location + 1])
			q.push({ location + 1,time + 1 });
		if (location * 2 <= MAX && !map[location * 2])
			q.push({ location * 2 ,time + 1 });
	}
	return -1;
}

int main() {
	int N, K;
	cin >> N >> K;
	cout << bfs(N, K);
	return 0;
}