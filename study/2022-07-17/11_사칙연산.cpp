#include <vector>
#include <string>
#include <cstdlib>
#define MAX 201
#define INF 3000000

using namespace std;

/*
    https://school.programmers.co.kr/learn/courses/30/lessons/1843
*/

int N;
int maxDP[MAX][MAX], minDP[MAX][MAX];

int min(int a, int b) {
	if (a == INF) return b;
	if (b == INF) return a;
	return a < b ? a : b;
}

int max(int a, int b) {
	if (a == INF) return b;
	if (b == INF) return a;
	return a < b ? b : a;
}

int getMAX(int s, int e, vector<string>& arr);
int getMIN(int s, int e, vector<string>& arr);

int getMAX(int s, int e, vector<string>& arr) {
	int& ret = maxDP[s][e];
	if (ret != INF) return ret;

	for (int i = s + 1; i < e; i += 2) {
		if (arr[i] == "+") {
			ret = max(ret, getMAX(s, i - 1, arr) + getMAX(i + 1, e, arr));
		}
		else {
			ret = max(ret, getMAX(s, i - 1, arr) - getMIN(i + 1, e, arr));
		}
	}
	return ret;
}

int getMIN(int s, int e, vector<string>& arr) {
	int& ret = minDP[s][e];
	if (ret != INF) return ret;

	for (int i = s + 1; i < e; i += 2) {
		if (arr[i] == "+") {
			ret = min(ret, getMIN(s, i - 1, arr) + getMIN(i + 1, e, arr));
		}
		else {
			ret = min(ret, getMIN(s, i - 1, arr) - getMAX(i + 1, e, arr));
		}
	}
	return ret;
}

int solution(vector<string> arr)
{
	N = arr.size();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			maxDP[i][j] = minDP[i][j] = INF;
		}
	}
	for (int i = 0; i < N; i += 2) {
		maxDP[i][i] = minDP[i][i] = stoi(arr[i]);
	}
	int answer = -1;
	answer = getMAX(0, N - 1, arr);
	return answer;
}