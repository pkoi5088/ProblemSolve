#include <iostream>
#include <string>
#include <algorithm>
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
		int N;
		string ret = "No", in;
		cin >> in;
		sort(in.begin(), in.end());
		if (in[0] == in[1] && in[2] == in[3] && in[0] != in[2]) ret = "Yes";
		cout << '#' << test_case << ' ' << ret << endl;
	}
	return 0;
}