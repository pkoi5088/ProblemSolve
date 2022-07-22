#include <iostream>
#include <string>
#include <vector>
#define MAX 20000
using namespace std;

/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12983
*/ 

int N;
//dp[i]: t[i:]에서 만들수 있는 경우의수
int dp[MAX];

int min(int a, int b) {
    if (a == -2) return b;
    if (b == -2) return a;
    return a < b ? a : b;
}

//p가 t안에 존재하는가
bool check(string t, int length, string p) {
    if (p.size() > t.size() - length) return false;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] != t[i + length]) return false;
    }
    return true;
}

int getDP(int idx, vector<string>& strs,string& t) {
    if (idx >= N) return 0;
    int& ret = dp[idx];
    if (ret != -2) return ret;

    for (int i = 0; i < strs.size(); ++i) {
        if (check(t, idx, strs[i])) {
            int tmp = getDP(idx + strs[i].size(), strs, t);
            if (tmp != -2) {
                ret = min(ret, tmp + 1);
            }
        }
    }
    return ret;
}

int solution(vector<string> strs, string t)
{
    int answer = 0;
    N = t.size();
    for (int i = 0; i < N; ++i) {
        dp[i] = -2;
    }
    answer = getDP(0, strs, t);
    if (answer == -2) return -1;
    return answer;
}