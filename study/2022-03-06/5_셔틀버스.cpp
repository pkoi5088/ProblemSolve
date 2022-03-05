#include <string>
#include <vector>
#include <algorithm>
#define MAX 1440

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/17678
*/

int bustime[MAX] = { 0, };

int timeToInt(string s) {
    int ret = 0;
    ret += (s[0] - '0') * 10 * 60;
    ret += (s[1] - '0') * 60;
    ret += (s[3] - '0') * 10;
    ret += (s[4] - '0');
    return ret;
}

string intToTime(int i) {
    string ret;
    ret.push_back(i % 10 + '0');
    i /= 10;
    ret.push_back(i % 6 + '0');
    i /= 6;
    ret.push_back(':');
    ret.push_back(i % 10 + '0');
    i /= 10;
    ret.push_back(i % 10 + '0');
    reverse(ret.begin(), ret.end());
    return ret;
}

//deadline까지(포함)서있는 승객들을 m명 태운다
void preFunction(int deadline, int m) {
    int now = 0;
    while (now <= deadline && m > 0) {
        if (bustime[now] != 0) {
            bustime[now] -= 1;
            m -= 1;
        }
        else {
            now += 1;
        }
    }
}

string solution(int n, int t, int m, vector<string> timetable) {
    //시간입력
    for (string s : timetable) {
        bustime[timeToInt(s)] += 1;
    }

    //마지막버스를 제외한 승객 탑승
    for (int i = 0, deadline = 9 * 60; i < n - 1; i++, deadline += t) {
        preFunction(deadline, m);
    }

    //포함X deadline계산, now계산(now는 승객이 존재한다)
    int deadline = 9 * 60 + t * (n - 1), now = 0;
    preFunction(deadline - 1, m - 1);
    while (now < MAX && bustime[now] == 0)
        now += 1;
    
    if (deadline < now) return intToTime(deadline);
    else return intToTime(now - 1);
}