#include <iostream>
#include <vector>
#define MAX 200000
#define endl '\n'

using namespace std;

/*
    1. Node가 1개 O
    2. 가지가 없다
    3. Root가 기가노드 O
	4. 정상
*/

vector<pair<int,int>> graph[MAX];
int N,R;

void searchGiga(int root,int& retIdx,int& retDist,int& retParnet){
	int now=root,parent=-1;
	retDist=0,retIdx=root;

	//root가 기가노드일 경우
	if(graph[now].size()>=2)
		return;
	
	retDist+=graph[now][0].second;
	parent=now;
	now=graph[now][0].first;
	while(!(graph[now].size()==1||graph[now].size()>2)){
		for(int i=0;i<graph[now].size();++i){
			int next=graph[now][i].first,nextDist=graph[now][i].second;
			if(parent!=next){
				retDist+=nextDist;
				parent=now;
				now=next;
				break;
			}
		}
	}
	retIdx=now;
	retParnet=parent;
}

int searchBranch(int start,int parnet){
	int ret=0;
	for(int i=0;i<graph[start].size();++i){
		int next=graph[start][i].first,nextDist=graph[start][i].second;
		if(next!=parnet){
			ret=max(ret,searchBranch(next,start)+nextDist);
		}
	}
	return ret;
}

void solve() {
    cin>>N>>R;
	for(int i=0;i<N-1;++i){
		int a,b,d;
		cin>>a>>b>>d;
		graph[a-1].push_back({b-1,d});
		graph[b-1].push_back({a-1,d});
	}

	if(N==1){
		cout<<"0 0"<<endl;
		return;
	}
	int poleIdx,poleLength,branchLength,parent=-1;
	searchGiga(R-1,poleIdx,poleLength,parent);
	if(graph[poleIdx].size()==1){
		branchLength=0;
	}else{
		branchLength=searchBranch(poleIdx,parent);
	}
	cout<<poleLength<<' '<<branchLength<<endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}