#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/7453
*/

vector<int> arr[4];
vector<int> mergearr[2];

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<4;++i)
        arr[i].resize(n);
    for(int i=0;i<n;++i)
        cin>>arr[0][i]>>arr[1][i]>>arr[2][i]>>arr[3][i];
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            mergearr[0].push_back(arr[0][i]+arr[1][j]);
            mergearr[1].push_back(arr[2][i]+arr[3][j]);
        }
    }
    sort(mergearr[0].begin(),mergearr[0].end());
    sort(mergearr[1].begin(),mergearr[1].end());

    long long ret=0;
    int left=0,right=mergearr[0].size()-1;
    while(left<mergearr[0].size()&&right>=0){
        if(mergearr[0][left]+mergearr[1][right]==0){
            int tmpleft=left,tmpright=right;
            while(tmpleft<mergearr[0].size()&&mergearr[0][left]==mergearr[0][tmpleft])
                tmpleft+=1;
            while(tmpright>=0&&mergearr[1][right]==mergearr[1][tmpright])
                tmpright-=1;

            ret+=(long long)(tmpleft-left)*(long long)(right-tmpright);
            left=tmpleft;
            right=tmpright;
        }else if(mergearr[0][left]+mergearr[1][right]>0){
            right-=1;
        }else{
            left+=1;
        }
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