#include<iostream>
#include <cstdio>
#define endl '\n'

using namespace std;

int max(int a, int b, int c, int d) {
	return (max(max(a, b), max(c, d)));
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T = 10;
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		/* 구현 */
		int N, ret = -1, lowIdx = -1, highIdx = -1, arr[101] = { 0, };
		cin >> N;
		for (int i = 0; i < 100; ++i) {
			int tmp;
			cin >> tmp;
			arr[tmp] += 1;
			if (lowIdx == -1 || lowIdx > tmp) lowIdx = tmp;
			if (highIdx == -1 || highIdx < tmp) highIdx = tmp;
		}

		while (abs(highIdx - lowIdx) > 1 && lowIdx <= highIdx && N > 0) {
			arr[highIdx] -= 1;
			arr[highIdx - 1] += 1;
			arr[lowIdx] -= 1;
			arr[lowIdx + 1] += 1;
			while (arr[highIdx] == 0) highIdx -= 1;
			while (arr[lowIdx] == 0) lowIdx += 1;
			N -= 1;
		}
		if (lowIdx >= highIdx) ret = 0;
		else ret = highIdx - lowIdx;
		cout << '#' << test_case << ' ' << ret << endl;
	}
	return 0;
}