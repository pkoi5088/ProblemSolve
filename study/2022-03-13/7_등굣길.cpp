#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/42898
*/

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n, vector<int>());
    for (int i = 0; i < n; ++i)
        dp[i].resize(m, -1);
    dp[0][0] = 1;
    for (vector<int> p : puddles) {
        dp[p[1] - 1][p[0] - 1] = 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp[i][j] == 0) continue;
            //왼쪽
            if (i != 0 || j != 0)
                dp[i][j] = 0;
            if (j != 0) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j]%=MOD;
            }
            //위
            if (i != 0) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j]%=MOD;
            }
        }
    }
    answer = dp[n - 1][m - 1];
    return answer;
}