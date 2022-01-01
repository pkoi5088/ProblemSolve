#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/17686
*/

string toUpper(string s) {
    string ret;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z')
            ret.push_back(s[i] - 'a' + 'A');
        else
            ret.push_back(s[i]);
    }
    return ret;
}

bool isNum(char c) {
    return c >= '0' && c <= '9';
}

int toNumber(string s) {
    int ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

bool cmp(string s1, string s2) {
    string s1sub, s2sub;
    int s1Idx = 0, s1End, s2Idx = 0, s2End;
    while (!isNum(s1[s1Idx]))
        s1Idx++;
    while (!isNum(s2[s2Idx]))
        s2Idx++;
    s1sub = toUpper(s1.substr(0, s1Idx));
    s2sub = toUpper(s2.substr(0, s2Idx));
    if (s1sub != s2sub) return s1sub < s2sub;
    for (s1End = s1Idx + 1; s1End < s1.size() && isNum(s1[s1End]); ++s1End);
    for (s2End = s2Idx + 1; s2End < s2.size() && isNum(s2[s2End]); ++s2End);
    if (toNumber(s1.substr(s1Idx, s1End - s1Idx)) != toNumber(s2.substr(s2Idx, s2End - s2Idx)))
        return toNumber(s1.substr(s1Idx, s1End - s1Idx)) < toNumber(s2.substr(s2Idx, s2End - s2Idx));
    return false;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}