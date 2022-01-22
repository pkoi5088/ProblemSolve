#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/42895
*/

set<long long> setArr[9];

int solution(int N, int number) {
    int tmp = 1;
    for (int i = 1; i <= 8; ++i) {
        setArr[i].insert(tmp * N);
        for (int j = 1; j < i; ++j) {
            for (int x : setArr[j]) {
                for (int y : setArr[i - j]) {
                    setArr[i].insert(x + y);
                    if (x - y >= 0)
                        setArr[i].insert(x - y);
                    setArr[i].insert(x * y);
                    if (y > 0)
                        setArr[i].insert(x / y);
                }
            }
        }
        tmp *= 10;
        tmp += 1;
    }
    int answer = -1;
    for (int i = 1; i < 9; ++i) {
        for (set<long long>::iterator iter = setArr[i].begin(); iter != setArr[i].end(); ++iter) {
            if (*iter == number) {
                return i;
            }
        }
    }
    return answer;
}