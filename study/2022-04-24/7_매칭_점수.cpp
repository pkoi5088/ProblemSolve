#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/42893
*/

struct Node {
	int idx;
	int basic, out;
	double link, match;
	Node() {
		idx = basic = out = link = match = 0;
	}
};

bool cmp(Node n1, Node n2) {
	if (n1.match == n2.match) {
		return n1.idx < n2.idx;
	}
	return n1.match > n2.match;
}

//소문자 변환
void toUnder(string& s) {
	for (int i = 0; i < s.size(); ++i) {
		if (isupper(s[i])) {
			s[i] -= 'A' - 'a';
		}
	}
}

//사이트 이름 찾기
string findName(string s) {
	string tmp = "<meta property=\"og:url\" content=\"", ret;
	int idx = s.find(tmp) + tmp.size();
	while (s[idx] != '\"') {
		ret.push_back(s[idx]);
		idx += 1;
	}
	return ret;
}

//기본점수 구하기
int getBasic(string s,string word) {
	int ret = 0;
	int idx1 = s.find("<body>") + 6, idx2 = s.find("</body>");
	
	string tmp;
	for (int i = idx1; i < idx2; ++i) {
		if (isalpha(s[i])) {
			tmp += s[i];
		}
		else {
			if (tmp == word) {
				ret += 1;
			}
			tmp.clear();
		}
	}
	return ret;
}

//외부링크 주소 반환
vector<string> getOut(string s) {
	vector<string> ret;
	string tmp = "<a href=\"";
	int idx = s.find(tmp);
	while (idx != string::npos) {
		idx += tmp.size();
		string t;
		while (s[idx] != '\"') {
			t.push_back(s[idx]);
			idx += 1;
		}
		ret.push_back(t);
		idx = s.find(tmp, idx);
	}
	return ret;
}

int solution(string word, vector<string> pages) {
	vector<Node> v(pages.size());
	vector<vector<int>> indegree(pages.size());
	map<string, int> table;
    int answer = 0;
	//소문자 변환
	toUnder(word);
	for (string& s : pages) {
		toUnder(s);
	}
	
	//각 웹페이지 이름 구하기
	for (int i = 0; i < pages.size();++i) {
		v[i].idx = i;
		table[findName(pages[i])] = i;
	}

	//기본점수 구하기
	for (int i = 0; i < pages.size(); ++i) {
		v[i].basic = getBasic(pages[i], word);
	}

	//외부점수 구하기
	for (int i = 0; i < pages.size(); ++i) {
		vector<string> vout = getOut(pages[i]);
		v[i].out = vout.size();
		for (string outurl : vout) {
			if (table.find(outurl) != table.end()) {
				int idx = table[outurl];
				indegree[idx].push_back(i);
			}
		}
	}

	//링크점수 구하기
	for (int i = 0; i < pages.size(); ++i) {
		for (int outIdx : indegree[i]) {
			v[i].link += (double)v[outIdx].basic / (double)v[outIdx].out;
		}
	}

	//매칭점수 계산하기
	for (int i = 0; i < pages.size(); ++i) {
		v[i].match = (double)v[i].basic + v[i].link;
	}

	//정렬
	sort(v.begin(), v.end(), cmp);
	answer = v[0].idx;

    return answer;
}