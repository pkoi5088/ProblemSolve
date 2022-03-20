#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/43163
*/

bool check(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) cnt += 1;
    }
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0, beginIdx = -1, targetIdx = -1;
    for (int i = 0; i < words.size(); ++i) {
        if (begin == words[i]) beginIdx = i;
        if (target == words[i]) targetIdx = i;
    }
    if (beginIdx == -1) {
        words.push_back(begin);
        beginIdx = words.size() - 1;
    }
    vector<vector<int>> graph(words.size());
    vector<bool> visit(words.size(), false);
    
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            if (check(words[i], words[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    if (targetIdx == -1) {
        return 0;
    }

    queue<pair<int,int>> q;
    q.push({ beginIdx,0 });
    visit[beginIdx] = true;
    while (!q.empty()) {
        int now = q.front().first, ret = q.front().second;
        q.pop();
        if (now == targetIdx) return ret;
        
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i];
            if (visit[next]) continue;
            q.push({ next,ret + 1 });
        }
    }
}