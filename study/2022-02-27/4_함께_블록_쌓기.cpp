#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
#define MAX_N 50
#define MAX_H 1001
#define MOD 10007
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/18427
*/

vector<int> arr[MAX_N];
int dp[MAX_N][MAX_H];
int N,M,H;

int getDP(int n,int h){
    int& ret=dp[n][h];
    if(ret!=-1) return ret;

    //기저사례
    if(n==0){
        if(h==0) return ret=1;
        for(int i=0;i<arr[n].size();++i){
            if(arr[n][i]==h) return ret=1;
        }
        return ret=0;
    }

    //각각의 블록에 대해서
    ret=getDP(n-1,h)%MOD;
    for(int i=0;i<arr[n].size();++i){
        if(h-arr[n][i]>=0){
            ret+=getDP(n-1,h-arr[n][i]);
            ret%=MOD;
        }
    }
    return ret%MOD;
}

void solve() {
    memset(dp,-1,sizeof(dp));
    cin>>N>>M>>H;
    cin.ignore();
    for(int i=0;i<N;++i){
        string s,tmp="";
        getline(cin,s);
        s.push_back(' ');
        for(int j=0;j<s.size();++j){
            if(s[j]==' '){
                arr[i].push_back(stoi(tmp));
                tmp.clear();
            }else{
                tmp.push_back(s[j]);
            }
        }
    }
    cout<<getDP(N-1,H);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}