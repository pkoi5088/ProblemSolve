#include <string>
#include <vector>
#include <algorithm>
#define MAX 10000

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/43164
*/

bool visit[MAX] = { false, };

void dfs(string now, vector<vector<string>> tickets, int cnt, vector<string>& answer,vector<string>& tmp) {
    if (!answer.empty()) return;
    if (cnt == tickets.size()) {
        answer = tmp;
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == now && visit[i] == false) {
            visit[i] = true;
            tmp.push_back(tickets[i][1]);
            dfs(tickets[i][1], tickets, cnt + 1, answer, tmp);
            tmp.pop_back();
            visit[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer,tmp;
    sort(tickets.begin(), tickets.end());
    tmp.push_back("ICN");
    dfs("ICN", tickets, 0, answer, tmp);
    return answer;
}