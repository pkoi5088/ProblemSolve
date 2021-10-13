#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#define MAX 4000000
#define endl '\n'

using namespace std;

int num[MAX], pick[MAX], parent[MAX];
int N, M, K;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

//num배열에서 number보다 큰 수가 처음 나오는 인덱스 return
int getUpper(int number) {
	int low = 0, high = M - 1, ret;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (num[mid] <= number) {
			low = mid + 1;
		}
		else {
			ret = mid;
			high = mid - 1;
		}
	}
	return ret;
}

void solve() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i) {
		cin >> num[i];
		parent[i] = i;
	}
	sort(num, &num[M]);
	for (int i = 0; i < M; ++i) {
		cin >> pick[i];
	}

	for (int i = 0; i < K; ++i) {
		int idx = getUpper(pick[i]);
		cout << num[Find(idx)] << endl;
		parent[Find(idx)] += 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
