#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'	

using namespace std;

/*
	https://www.acmicpc.net/problem/8980
*/

class Node{
	public:
	int from,to,count;
};

bool cmp(Node& n1,Node& n2){
	if(n1.to==n2.to)
		return n1.from<n2.from;
	return n1.to<n2.to;
}

void solve() {
    int N,C,M;
	vector<Node> village;
	vector<int> box;
	cin>>N>>C>>M;
	village.resize(M);
	box.resize(N+1,0);
	for(int i=0;i<M;++i){
		cin>>village[i].from>>village[i].to>>village[i].count;
	}
	sort(village.begin(),village.end());

	for(int i=0;i<M;++i){
		int start=village[i].from,end=village[i].to;
		int minBox=min(village[i].count,C-village[i].count);
		for(int j=start;j<=end;++j){
			minBox=min(minBox,village[j].count);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}