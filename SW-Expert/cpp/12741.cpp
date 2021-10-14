#include<iostream>
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
		int A, B, C, D, ret = -1;
		cin >> A >> B >> C >> D;
		ret = min(B, D) - max(A, C);
		if (ret < 0) ret = 0;
		cout << '#' << test_case << ' ' << ret << endl;
	}
	return 0;
}