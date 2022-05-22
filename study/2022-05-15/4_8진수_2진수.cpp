#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1212
*/

void solve() {
    vector<string> v={"000","100","010","110","001","101","011","111"};
    string s,ret;
    cin>>s;
    if(s=="0") cout<<s;
    else{
        for(int i=s.size()-1;i>=0;--i){
            ret+=v[s[i]-'0'];
        }
        while(ret.back()=='0')
            ret.pop_back();
        reverse(ret.begin(),ret.end());
        cout<<ret;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}