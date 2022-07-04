#include <cmath>

/*
    https://programmers.co.kr/learn/courses/30/lessons/1831
*/

int dfs(int n, int cnt) {
	int ret = 0;
	if (n < 1||2*log(n)/log(3)<cnt) return 0;
	if (n == 3 && cnt == 2) return 1;

	if (n % 3 == 0 && cnt >= 2)
		ret += dfs(n / 3, cnt - 2);
	ret += dfs(n - 1, cnt + 1);
	return ret;
}

int solution(int n) {
	int answer = dfs(n - 2, 2);
	return answer;
}