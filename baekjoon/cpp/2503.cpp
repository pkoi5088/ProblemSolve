#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2503
*/

vector<pair<int, pair<int, int>>> v;
int N;

bool numCheck(int num) {
	int a = num / 100, b = (num % 100) / 10, c = num % 10;
	if (a == b || a == c || b == c) return false;
	if (a * b * c == 0) return false;
	return true;
}

//num가 v에 대해서 유효한가
bool check(int num) {
	for (int i = 0; i < N; ++i) {
		int target = v[i].first, tstrike = v[i].second.first, tball = v[i].second.second;
		int num1 = num / 100, num2 = (num % 100) / 10, num3 = num % 10;
		int tar1 = target / 100, tar2 = (target % 100) / 10, tar3 = target % 10;

		//1
		if (num1 == tar1) {
			tstrike -= 1;
		}
		else if (num1 == tar2 || num1 == tar3) {
			tball -= 1;
		}
		//2
		if (num2 == tar2) {
			tstrike -= 1;
		}
		else if (num2 == tar1 || num2 == tar3) {
			tball -= 1;
		}
		//3
		if (num3 == tar3) {
			tstrike -= 1;
		}
		else if (num3 == tar1 || num3 == tar2) {
			tball -= 1;
		}

		if (tstrike != 0 || tball != 0) return false;
	}
	return true;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,{b,c} });
	}

	int ret = 0;
	for (int i = 0; i < 1000; ++i) {
		if (!numCheck(i)) continue;
		if (check(i)) ret += 1;
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}