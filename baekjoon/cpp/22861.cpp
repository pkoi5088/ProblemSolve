#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/22861
*/

class Folder {
public:
	string name;
	set<string> files;
	vector<string> folders;
	string parent;
	
	Folder(string n) {
		name = n;
	}
};

int N, M, K, Q;
map<string, Folder*> folderTable;
map<string, pair<set<string>, int>> cache;

Folder* getFolderPtr(string name) {
	if (folderTable.find(name) == folderTable.end()) {
		Folder* tmp = new Folder(name);
		folderTable[name] = tmp;
	}
	return folderTable[name];
}

void correction(string& s) {
	string ret;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '/') {
			ret.clear();
		}
		else {
			ret.push_back(s[i]);
		}
	}
	s = ret;
}

pair<set<string>, int> getCache(string name) {
	if (cache.find(name) != cache.end())
		return cache[name];
	Folder* folder = getFolderPtr(name);
	set<string> tmpSet(folder->files);
	int tmpCnt = folder->files.size();
	for (int i = 0; i < folder->folders.size(); ++i) {
		pair<set<string>, int> child = getCache(folder->folders[i]);
		for (auto iter : child.first) {
			tmpSet.insert(iter);
		}
		tmpCnt += child.second;
	}
	cache[name] = { tmpSet,tmpCnt };
	return cache[name];
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N + M; ++i) {
		string a, b;
		int c;
		cin >> a >> b >> c;
		if (c == 0) {
			Folder* folderA = getFolderPtr(a);
			folderA->files.insert(b);
		}
		else {
			Folder* folderA = getFolderPtr(a);
			Folder* folderB = getFolderPtr(b);
			folderA->folders.push_back(b);
			folderB->parent = a;
		}
	}

	//폴더정리
	cin >> K;
	while (K--) {
		string a, b;
		cin >> a >> b;
		correction(a); correction(b);

		Folder* folderA = getFolderPtr(a);
		Folder* folderB = getFolderPtr(b);

		//A하위를 B로
		//폴더옮기기,parent설정
		for (int i = 0; i < folderA->folders.size(); ++i) {
			folderB->folders.push_back(folderA->folders[i]);
			Folder* child = getFolderPtr(folderA->folders[i]);
			child->parent = b;
		}
		//파일옮기기
		for (auto iter = folderA->files.begin(); iter != folderA->files.end(); ++iter) {
			folderB->files.insert(*iter);
		}
		//table에서 A삭제
		delete folderTable[a];
		folderTable.erase(a);
	}

	//쿼리
	cin >> Q;
	while (Q--) {
		string s;
		cin >> s;
		correction(s);

		pair<set<string>, int> tmp = getCache(s);
		cout << tmp.first.size() << ' ' << tmp.second << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}