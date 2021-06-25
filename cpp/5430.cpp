#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	string instructions,inNums;
	deque<int> numbers;
	int N;
	cin >> instructions >> N >> inNums;
	int i = 1;
	while (i < inNums.size()) {
		int R;
		string s = "";
		while (inNums[i] >= '0' && inNums[i] <= '9') {
			s += inNums[i];
			i += 1;
		}
		if (s != "") {
			R = stoi(s);
			numbers.push_back(R);
		}
		i += 1;
	}

	//0-왼쪽에서 오른쪽 1-오른쪽에서 왼쪽
	int dir = 0;
	for (int index = 0; index < instructions.size(); index++) {
		if (instructions[index] == 'R') {
			dir = !dir;
		}
		else {
			if (numbers.empty()) {
				cout << "error\n";
				return;
			}
			else {
				if (dir) {
					numbers.pop_back();
				}
				else {
					numbers.pop_front();
				}
			}
		}
	}

	cout << '[';
	if (dir) {
		for (int i = numbers.size() - 1; i >= 0; i--) {
			cout << numbers[i];
			if (i != 0)
				cout << ',';
		}
	}
	else {
		for (int i = 0; i < numbers.size(); i++) {
			cout << numbers[i];
			if (i != numbers.size() - 1)
				cout << ',';
		}
	}
	cout << ']' << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
