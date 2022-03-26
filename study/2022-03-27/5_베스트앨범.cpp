#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

/* 
    https://programmers.co.kr/learn/courses/30/lessons/42579
*/

struct cmp {
    bool operator()(pair<int, int>p1, pair<int, int> p2) {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }
        else
            return p1.second < p2.second;
    }
};

bool compare(pair<int, priority_queue <pair<int, int>, vector<pair<int, int>>, cmp>>p1, pair<int, priority_queue <pair<int, int>, vector<pair<int, int>>, cmp>>p2) {
    return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genresToIdx;
    //first.first 고유번호 first.second 횟수
    vector<pair<int, priority_queue <pair<int, int>, vector<pair<int, int>>, cmp>>> v;
    for (int i = 0; i < genres.size(); ++i) {
        int idx;
        if (!genresToIdx.count(genres[i])) {
            genresToIdx[genres[i]] = genresToIdx.size();
            v.push_back({ 0,priority_queue <pair<int, int>, vector<pair<int, int>>, cmp>() });
        }
        idx = genresToIdx[genres[i]];
        v[idx].first += plays[i];
        v[idx].second.push({ i,plays[i] });
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); ++i) {
        int N = 2;
        while (N-- && !v[i].second.empty()) {
            answer.push_back(v[i].second.top().first);
            v[i].second.pop();
        }
    }
    return answer;
}