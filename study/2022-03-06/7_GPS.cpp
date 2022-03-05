#include <cstring>
#include <string>
#include <vector>
#define INF 1000000

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/1837#
*/

//idx에서 number일때 시작부터 idx까지의 수정회수의 최소값
int getDP(int idx, int number, vector<vector<int>>& dp, vector<vector<int>>& graph,vector<int>& gps_log) {
    if (idx < 0) return INF;
    int& ret = dp[idx][number];
    if (ret != INF) return ret;

    for (int i = 0; i < graph[number].size(); ++i) {
        ret = min(ret, getDP(idx - 1, graph[number][i],dp,graph,gps_log) + (gps_log[idx] - 1 == number ? 0 : 1));
    }
    if (ret == INF) return ret = INF - 1;
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    vector<vector<int>> graph(n), dp(k);
    for (int i = 0; i < k; ++i)
        dp[i].resize(n, INF);
    for (int i = 0; i < edge_list.size(); ++i) {
        graph[edge_list[i][0] - 1].push_back(edge_list[i][1] - 1);
        graph[edge_list[i][1] - 1].push_back(edge_list[i][0] - 1);
    }
    for (int i = 0; i < n; ++i)
        graph[i].push_back(i);
    dp[0][gps_log[0]-1] = 0;

    int answer = 0;
    answer = getDP(gps_log.size() - 1, gps_log[k-1]-1,dp,graph, gps_log);
    if (answer > k) return -1;
    return answer;
}