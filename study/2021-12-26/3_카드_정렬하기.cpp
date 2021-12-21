#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/13975
*/

void solve() {
    priority_queue<int> pq;
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int tmp;
        cin>>tmp;
        pq.push(-tmp);
    }
    
    int ret=0;
    while(pq.size()>1){
        int a,b;
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        ret+=-(a+b);
        pq.push(a+b);
    }
    cout<<ret<<endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}