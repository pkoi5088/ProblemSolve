#include <iostream>
#include <cstring>
#define MAX_N 10000
#define MAX_K 14
#define endl '\n'

using namespace std;

void setLevel(int* level,int* parent,int idx){
    if(level[idx]!=-1) return;

    if(parent[idx]==-1) level[idx]=1;
    else{
        setLevel(level,parent,parent[idx]);
        level[idx]=level[parent[idx]]+1;
    }
}

void solve() {
    int N,A,B,root;
    int parent[MAX_N],dp[MAX_N][MAX_K],level[MAX_N];
    memset(parent,-1,sizeof(parent));
    memset(dp,-1,sizeof(dp));
    memset(level,-1,sizeof(level));   
    for(int i=0;i<N-1;++i){
        cin>>A>>B;
        parent[B-1]=A-1;
    }

    //root찾으면서 level세팅
    for(int i=0;i<N;++i){
        if(parent[i]==-1) root=i;
        setLevel(level,parent,i);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
	    solve();
	return 0;
}