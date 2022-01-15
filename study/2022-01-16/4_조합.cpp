#include <iostream>
#include <algorithm>
#define MAX 101
#define endl '\n'


using namespace std;

/*
	https://www.acmicpc.net/problem/2407
*/

string dp[MAX][MAX];

string sumStr(string s1,string s2){
    string ret;
    int tmp=0;
    while(!s1.empty()&&!s2.empty()){
        tmp+=s1.back()-'0'+s2.back()-'0';
        s1.pop_back(); s2.pop_back();
        ret.push_back(tmp%10+'0');
        tmp/=10;
    }

    while(!s1.empty()){
        tmp+=s1.back()-'0';
        s1.pop_back();
        ret.push_back(tmp%10+'0');
        tmp/=10;
    }

    while(!s2.empty()){
        tmp+=s2.back()-'0';
        s2.pop_back();
        ret.push_back(tmp%10+'0');
        tmp/=10;
    }
    if(tmp)
        ret.push_back(tmp%10+'0');
    reverse(ret.begin(),ret.end());
    return ret;
}

string getDP(int n,int m){
    if(dp[n][m]!="") return dp[n][m];
    
    if(m==0||m==n) return dp[n][m]="1";
    return dp[n][m]=sumStr(getDP(n-1,m-1),getDP(n-1,m));
}

void solve() {
    int N,M;
    cin>>N>>M;
    cout<<getDP(N,M);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}