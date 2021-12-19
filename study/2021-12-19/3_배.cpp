#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1092
*/

void solve() {
    int N,M;
    vector<int> limit,box;
    cin>>N;
    limit.resize(N);
    for(int i=0;i<N;++i)
        cin>>limit[i];
    cin>>M;
    box.resize(M);
    for(int i=0;i<M;++i)
        cin>>box[i];

    sort(limit.begin(),limit.end());
    sort(box.begin(),box.end());
    if(limit[N-1]<box[M-1]){
        cout<<-1;
        return;
    }

    int ret=0;
    while(!box.empty()){
        vector<int> tmp;
        for(int i=N-1,j=box.size()-1;i>=0&&j>=0;){
            if(limit[i]>=box[j]){
                tmp.push_back(j);
                i-=1;
            }
            j-=1;
        }
        for(int i=0;i<tmp.size();++i){
            box.erase(box.begin()+tmp[i]);
        }
        ret+=1;
    }
    cout<<ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}