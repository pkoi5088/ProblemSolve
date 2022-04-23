#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/77886#
*/

vector<string> solution(vector<string> s) {
    for (string& t : s) {
        string tmp;
        int idx=0,cnt=0;
        while (idx < t.size()) {
            if (tmp.size()>=2&&t[idx] == '0') {
                if (tmp[tmp.size() - 1] == tmp[tmp.size() - 2] && tmp[tmp.size() - 1] == '1') {
                    tmp.pop_back();
                    tmp.pop_back();
                    cnt += 1;
                }
                else {
                    tmp.push_back(t[idx]);
                }
            }
            else {
                tmp.push_back(t[idx]);
            }
            idx += 1;
        }
        t = tmp;
        tmp.clear();
        idx = t.size() - 1;
        while (idx >= 0 && t[idx] != '0') {
            idx -= 1;
        }
        for (int i = 0; i <= idx; ++i) {
            tmp.push_back(t[i]);
        }
        while (cnt!=-1&&cnt) {
            tmp += "110";
            cnt -= 1;
        }
        for (int i = idx + 1; i < t.size(); ++i) {
            tmp.push_back(t[i]);
        }
        t = tmp;
    }
    return s;
}