#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

vector<int> parent;

int Find(int x){
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}

void Union(int a,int b){
    parent[Find(a)]=parent[Find(b)];
}

void solve() {
    int N;
    cin>>N;
    parent.resize(N);
    for(int i=0;i<N;++i)
        parent[i]=i;
    
    for(int i=0;i<N-2;++i){
        int a,b;
        cin>>a>>b;
        Union(a-1,b-1);
    }

    for(int i=1;i<N;++i){
        if(Find(0)!=Find(i)){
            cout<<1<<' '<<i+1;
            break;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}