#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/16404
*/

//트리에 이용될 idx를 저장, second는 자식의 최대 idx
vector<pair<int, int>> employee;
vector<int> segTree, lazyTree;
vector<vector<int>> child;
int N, M;

void numbering() {
	int number = 0;
	stack<int> s;
	s.push(0);
	while (!s.empty()) {
		int now = s.top();
		s.pop();

		employee[now].first = number;
		number += 1;

		for (int i = child[now].size() - 1; i >= 0; --i) {
			int next = child[now][i];
			s.push(next);
		}
	}
}

int getMaxIdx(int idx) {
	int& ret = employee[idx].second;
	if (ret != -1) return ret;

	if (child[idx].size() == 0) return ret = employee[idx].first;

	for (int i = 0; i < child[idx].size(); ++i) {
		int next = child[idx][i];
		ret = max(ret, getMaxIdx(next));
	}
	return ret;
}

/**
	idx: lazyTree에서의 현재 노드 idx
	start,end: lazyTree에서 idx가 나타내는 범위
	left,right: update하고자하는 범위
*/
void lazyQuery(int idx, int start, int end, int left, int right, int diff) {
	if (end<left || start>right) return;

	//완전 포함되는 경우
	if (start >= left && right >= end) {
		lazyTree[idx] += diff;
	}
	else {
		int mid = (start + end) / 2;
		lazyQuery(2 * idx + 1, start, mid, left, right, diff);
		lazyQuery(2 * idx + 2, mid + 1, end, left, right, diff);
	}
}

int query(int idx, int start, int end, int target) {
	if (start > target || end < target) return 0;

	if (start == target && target == end) {
		segTree[idx] += lazyTree[idx];
		lazyTree[idx] = 0;
		return segTree[idx];
	}
	else {
		int mid = (start + end) / 2;
		lazyTree[2 * idx + 1] += lazyTree[idx];
		lazyTree[2 * idx + 2] += lazyTree[idx];
		lazyTree[idx] = 0;
		return query(2 * idx+1, start, mid, target) + query(2 * idx + 2, mid + 1, end, target);
	}
}

void solve() {
	cin >> N >> M;
	employee.resize(N, { 0,-1 });
	child.resize(N);
	segTree.resize((1 << (int)(ceil(log2(N)) + 1)));
	lazyTree.resize((1 << (int)(ceil(log2(N)) + 1)));

	int idx = 0;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		if (tmp != -1) {
			child[tmp - 1].push_back(i);
		}
	}

	numbering();
	while (M--) {
		int x, i, w;
		cin >> x;
		if (x == 1) {
			cin >> i >> w;
			i -= 1;
			getMaxIdx(i);
			lazyQuery(0, 0, N - 1, employee[i].first, employee[i].second, w);
		}
		else {
			cin >> i;
			i -= 1;
			cout << query(0, 0, N - 1, employee[i].first) << endl;
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