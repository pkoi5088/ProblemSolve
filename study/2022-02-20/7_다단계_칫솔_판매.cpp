#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/77486
*/

vector<int> parent, profit;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    map<string, int> table;
    int N = enroll.size();
    parent.resize(N, -1);
    indegree.resize(N, 0);
    profit.resize(N, 0);
    //이름->idx저장
    for (int i = 0; i < N; ++i) {
        table[enroll[i]] = i;
    }
    //referral 처리
    for (int i = 0; i < N; ++i) {
        if (referral[i] == "-") {
            parent[i] = -1;
        }
        else {
            parent[i] = table[referral[i]];
        }
    }
    //seller처리
    for (int i = 0; i < seller.size(); ++i) {
        int now = table[seller[i]];
        int p,money=amount[i]*100;
        while (now != -1) {
            p = parent[now];
            profit[now] += money - money / 10;
            money /= 10;
            now = p;
        }
    }
    return profit;
}