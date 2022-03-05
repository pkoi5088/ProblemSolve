#include <string>
#include <vector>
#define MAX 8

bool table[(1 << MAX)] = { false, };

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/64064
*/

//user와 ban의 매칭
bool check(string u, string b) {
    if (u.size() != b.size()) return false;
    for (int i = 0; i < u.size(); ++i) {
        if (b[i] != '*' && u[i] != b[i]) return false;
    }
    return true;
}

//flag상태에서 banned[idx]에 매칭 가능한 user의 idx들을 반환
vector<int> getIdxs(vector<string>& user, vector<string>& banned, int idx, int flag) {
    vector<int> ret;
    for (int i = 0; i < user.size(); ++i) {
        //i번째 user가 이미 포함된 경우
        if (flag & (1 << i)) continue;
        if (check(user[i], banned[idx]))
            ret.push_back(i);
    }
    return ret;
}

//flag 현재 상태;
void dfs(vector<string>& user, vector<string>& banned, int idx, int& flag) {
    if (banned.size() <= idx) {
        table[flag] = true;
    }
    else {
        vector<int> v = getIdxs(user, banned, idx, flag);
        for (int i = 0; i < v.size(); ++i) {
            flag |= (1 << v[i]);
            dfs(user, banned, idx + 1, flag);
            flag &= ~(1 << v[i]);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0, flag = 0;
    dfs(user_id, banned_id, 0, flag);
    for (int i = 0; i < (1 << MAX); ++i)
        answer += table[i];
    return answer;
}