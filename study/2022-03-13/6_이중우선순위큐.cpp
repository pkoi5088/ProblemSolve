#include <string>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/42628
*/

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minpq;
    priority_queue<int, vector<int>, less<int>> maxpq;
    int cnt = 0;
    for (string s : operations) {
        if (s[0] == 'I') {
            int tmp = stoi(s.substr(2));
            cnt += 1;
            minpq.push(tmp);
            maxpq.push(tmp);
        }
        else {
            if (s[2] == '-') {
                if (!minpq.empty()) {
                    minpq.pop();
                    cnt -= 1;
                }
            }
            else {
                if (!maxpq.empty()) {
                    maxpq.pop();
                    cnt -= 1;
                }
            }
            if (cnt == 0) {
                while (!minpq.empty())
                    minpq.pop();
                while (!maxpq.empty())
                    maxpq.pop();
            }
        }
    }
    if (minpq.empty())
        answer = { 0,0 };
    else
        answer = { maxpq.top(),minpq.top() };
    return answer;
}