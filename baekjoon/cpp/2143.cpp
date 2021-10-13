#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 1000
#define endl '\n'

using namespace std;

vector<int> vA, vB;
int A[MAX], B[MAX];
int n, m, T;

int getLower(int num) {
	int low = 0, high = vB.size() - 1, result = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (vB[mid] == num) {
			result = mid;
			high = mid - 1;
		}
		else if (vB[mid] > num) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return result;
}

int getUpper(int num, int start) {
	int low = start, high = vB.size() - 1, result = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (vB[mid] == num) {
			result = mid;
			low = mid + 1;
		}
		else if (vB[mid] > num) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return result;
}

void solve() {
	cin >> T >> n;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		if (i != 0) {
			A[i] += A[i - 1];
		}
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> B[i];
		if (i != 0) {
			B[i] += B[i - 1];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			if (j == 0) {
				vA.push_back(A[i]);
			}
			else {
				vA.push_back(A[i] - A[j - 1]);
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			if (j == 0) {
				vB.push_back(B[i]);
			}
			else {
				vB.push_back(B[i] - B[j - 1]);
			}
		}
	}

	long long result = 0;
	sort(vB.begin(), vB.end());

	for (int i = 0; i < vA.size(); ++i) {
		int lower = getLower(T - vA[i]),higher;
		if (lower != -1) {
			higher = getUpper(T - vA[i], lower);
			result += higher - lower + 1;
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
