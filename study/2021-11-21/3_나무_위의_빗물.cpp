#include <iostream>
#include <vector>
#define MAX 500000
#define endl '\n'

using namespace std;

int graph[MAX]={0,};
int N,W;

void solve() {
    double ret=0.0;
    cin>>N>>W;
    for(int i=0;i<N-1;++i){
        int U,V;
        cin>>U>>V;
        graph[U-1]+=1;
        graph[V-1]+=1;
    }
    double cnt=0.0;
    for(int i=1;i<N;++i){
        if(graph[i]==1){
            cnt+=1.0;
        }
    }
    ret=W/cnt;
    cout<<fixed;
    cout.precision(6);
    cout<<ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
