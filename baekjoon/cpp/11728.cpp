#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

void solve() {
    vector<int> A,B,ret;
    int N,M;
    cin>>N>>M;
    A.resize(N);
    B.resize(M);
    ret.resize(N+M);
    for(int i=0;i<N;++i)
        cin>>A[i];
    for(int i=0;i<M;++i)
        cin>>B[i];

    for(int AIdx=0,BIdx=0,RIdx=0;RIdx<N+M;){
        if(AIdx>=N){
            ret[RIdx++]=B[BIdx++];
        }else if(BIdx>=M){
            ret[RIdx++]=A[AIdx++];
        }else{
            if(A[AIdx]<=B[BIdx]){
                ret[RIdx++]=A[AIdx++];
            }else{
                ret[RIdx++]=B[BIdx++];
            }
        }
    }
    for(int i=0;i<N+M;++i){
        cout<<ret[i]<<' ';
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}