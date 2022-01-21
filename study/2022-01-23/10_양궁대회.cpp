#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/92342
*/

void getScore(vector<int> v, vector<int> info, int& ret1, int& ret2) {
	ret1 = ret2 = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] > info[i])
			ret1 += 10 - i;
		else if (info[i] != 0)
			ret2 += 10 - i;
	}
}

vector<int> max(vector<int>& v1, vector<int>& v2) {
	int idx;
	for (idx = v1.size() - 1; idx >= 0; --idx) {
		if (v1[idx] != v2[idx]) break;
	}
	if (idx == -1) return v1;
	if (v1[idx] > v2[idx]) return v1;
	return v2;
}

void dfs(int idx, int rest, vector<int>& tmp, vector<int>& info, vector<int>& answer) {
	//계산
	if (idx > 10) {
		//현재점수계산
		int lion1, apeach1;
		getScore(tmp, info, lion1, apeach1);
		//이기지 못하면 스킵
		if (lion1 <= apeach1) return;

		//answer점수 최초계산
		if (answer.empty()) {
			answer = tmp;
			return;
		}
		//더 크게 이길경우
		int lion2, apeach2;
		getScore(answer, info, lion2, apeach2);
		if (lion2 - apeach2 < lion1 - apeach1) {
			answer = tmp;
		}
		else if (lion2 - apeach2 == lion1 - apeach1) {
			answer = max(answer, tmp);
		}
	}
	else {
		//idx==10일경우
		if (idx == 10) {
			tmp[idx] += rest;
			dfs(idx + 1, 0, tmp, info, answer);
			tmp[idx] -= rest;
		}
		else {
			//쏘거나
			if (rest >= info[idx] + 1) {
				tmp[idx] += info[idx] + 1;
				dfs(idx + 1, rest - (info[idx] + 1), tmp, info, answer);
				tmp[idx] -= info[idx] + 1;
			}
			
			//안쏜다
			dfs(idx + 1, rest, tmp, info, answer);
		}
	}
}

vector<int> solution(int n, vector<int> info) {
	vector<int> answer,tmp(11,0);
	dfs(0, n, tmp, info, answer);
	if (answer.empty()) answer.push_back(-1);
	return answer;
}