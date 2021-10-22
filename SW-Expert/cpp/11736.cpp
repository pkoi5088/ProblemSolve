#include <iostream>
#include <cstdio>
#define endl '\n'

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		/* 구현 */
		int N, ret = 0, arr[20];
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		for (int i = 1; i < N - 1; ++i) {
			int a = arr[i - 1], b = arr[i + 1];
			if (arr[i] > max(a, b) || arr[i] < min(a, b)) continue;
			ret += 1;
		}
		cout << '#' << test_case << ' ' << ret << endl;
	}
	return 0;
}