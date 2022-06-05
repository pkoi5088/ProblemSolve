#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12936
*/

vector<int> solution(int n, long long k) {
    vector<int> rest(n);
    vector<long long> fact(n + 1, 1);
    for (int i = 2; i <= n; ++i)
        fact[i] = i * fact[i - 1];
    for (int i = 0; i < n; ++i)
        rest[i] = i + 1;
    vector<int> answer;
    while (n) {
        int i = (k - 1) / fact[n - 1];
        answer.push_back(rest[i]);
        rest.erase(rest.begin() + i);
        k %= fact[n - 1];
        if (k == 0) k = fact[n - 1];
        n -= 1;
    }
    return answer;
}