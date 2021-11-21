#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1167
*/

vector<pair<int,int>> graph[MAX];
int N;
bool check[MAX];

void getFar(int start,int& resultIdx,int& resultDist){
    memset(check,false,sizeof(check));
    
    resultIdx=start;
    resultDist=0;
    //first: idx, second: dist;
    queue<pair<int,int>> q;
    q.push({start,0});
    check[start]=true;
    while(!q.empty()){
        int now=q.front().first,dist=q.front().second;
        q.pop();

        if(resultDist<dist){
            resultIdx=now;
            resultDist=dist;
        }

        for(int i=0;i<graph[now].size();++i){
            int next=graph[now][i].first,nextDist=graph[now][i].second;
            if(check[next]==false){
                q.push({next,dist+nextDist});
                check[next]=true;
            }
        }
    }
}

void solve() {
    cin>>N;
    for(int i=0;i<N;++i){
        int from;
        cin>>from;
        while(true){
            int to,dist;
            cin>>to;
            if(to==-1) break;
            cin>>dist;
            graph[from-1].push_back({to-1,dist});
            graph[to-1].push_back({from-1,dist});
        }
    }

    int retV,retV2,retD;
    getFar(0,retV,retD);
    getFar(retV,retV2,retD);
    cout<<retD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
