#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

void solve() {
    priority_queue<long long> pq;
    int K;
    cin>>K;
    for(int i=0;i<K;++i){
        long long tmp;
        cin>>tmp;
        pq.push(-tmp);
    }
    
    long long ret=0;
    while(pq.size()>1){
        long long a,b;
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
    int T;
    cin>>T;
    while(T--)
	    solve();
	return 0;
}